#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <bits/stdc++.h>

using std::map;
using std::set;
using std::string;
using std::vector;

class RentCarService
{
private:
    vector<Car> cars;            // Vector of cars
    map<string, Client> clients; // Map of clients with their passport number as key
    void addCar();               // Add a car to the vector with parameters from the manager
    void addClient();            // Add client to the map with parameters from the manager
    void rentCar();              // This function call Car* chooseCar() and Client* chooseClient(), ask date period from manager and if can rent the car to the client using function Car::addSchedule() and Client::addSchedule()
    void deleteRentSchedule();   // Delete rent schedule from the car and client call Client* choose Client using function Client::deleteSchedule()
    void showCars();             // Show cars all cars in the vector using function Car::showCar()
    void returnCar();            // Return car call Client* chooseClient() and call Client::deleteSchedule()
    void updateCar();            // Update car call Car* chooseCar() and ask parameters from the manager and call Car::updateMileage(), Car::updatePrice() or Car::updateDeposit()
    void deleteCar();            // Delete car call Car* chooseCar()
    Car *chooseCar();            // Choose car from the vector using function Car::showCar() and ask for the number of the car from the manager
    Client *chooseClient();      // Choose client: ask for the passpot number of the client and return the pointer to the client
public:
    RentCarService(); // Constructor
    void enterMenu(); // Enter menu ask manager to enter the option by number and call the function
};

class Car
{
private:
    string brand;                 // Brand
    string model;                 // Model
    string color;                 // Color
    string VIN;                   // VIN
    int year;                     // Year
    int mileage;                  // Mileage
    float price_per_day;          // Price per day
    int deposit;                  // Deposit
    set<ScheduleForCar> schedule; // Schedule for car

public:
    Car(string brand, string model, string color, string VIN, int year, int mileage, int price_per_day, int deposit); // Constructor
    Car();                                                                                                            // Constructor
    bool addSchedule(ScheduleForCar schedule);                                                                        // Add schedule to the set schedule if the car is available for this schedule and return true if the car is available for this schedule
    void deleteSchedule(ScheduleForCar schedule);                                                                     // Delete schedule
    void showSchedule();                                                                                              // Show schedule
    void showCar();                                                                                                   // Show car
    void updateMileage();                                                                                             // Update mileage ask manager to enter the new mileage which larger then before and update the mileage
    void updatePrice();                                                                                               // Update price ask manager to enter the new price and update the price
    void updateDeposit();                                                                                             // Update deposit ask manager to enter the new deposit and update the deposit
};

class Client
{
private:
    string name;                     // Name
    string surname;                  // Surname
    string date_of_birth;            // Date of birth
    string passport_number;          // Passport number
    string passport_expiration_date; // Passport expiration date
    string phone_number;             // Phone number
    string email;                    // Email
    string address;                  // Address
    set<ScheduleForClient> schedule; // Schedule for customer

public:
    Client(string name, string surname, string date_of_birth, string passport_number, string passport_expiration_date, string phone_number, string email, string address); // Constructor
    Client();                                                                                                                                                              // Constructor
    bool addSchedule(ScheduleForClient schedule);                                                                                                                          // Add schedule to the set schedule if the car is available for this schedule and return true if the car is available for this schedule
    void deleteSchedule();                                                                                                                                                 // Delete schedule: call showSchedule() and ask for the number of the schedule from the manager, call Car::deleteSchedule(ScheduleForClient schedule) and delete the schedule from the set schedule
    void showSchedule();                                                                                                                                                   // Show schedule
    void showClient();                                                                                                                                                     // Show client
};

class Schedule
{
private:
    int day_from;   // Day from
    int month_from; // Month from
    int year_from;  // Year from
    int day_to;     // Day to
    int month_to;   // Month to
    int year_to;    // Year to

public:
    bool operator<(Schedule &other);                                                              // Operator <
    Schedule(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to); // Constructor
    Schedule();                                                                                   // Constructor
};

class ScheduleForCar : public Schedule
{
private:
    Client *client; // Client

public:
    ScheduleForCar(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to, Client *client); // Constructor
    ScheduleForCar();                                                                                                   // Constructor
    void showScheduleForCar();                                                                                          // Show schedule for car
};

class ScheduleForClient : public Schedule
{
private:
    Car *car; // Car

public:
    ScheduleForClient(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to, Car *car); // Constructor
    ScheduleForClient();                                                                                             // Constructor
    void showScheduleForCustomer();                                                                                  // Show schedule for customer
};

#endif // CLASSES_HPP