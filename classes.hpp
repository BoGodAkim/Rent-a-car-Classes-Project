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
    map<string, Client> clients; // Map of clients with their phone number as key
    void addCar();               // Add car
    void addClient();            // Add client
    void rentCar();              // Rent car
    void deleteRentSchedule();   // Delete rent schedule
    void showCars();             // Show cars
    void returnCar();            // Return car
    void updateCar();            // Update car
    void deleteCar();            // Delete car
public:
    RentCarService(); // Constructor
    void enterMenu(); // Enter menu
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
    int price_per_day;            // Price per day
    int deposit;                  // Deposit
    set<ScheduleForCar> schedule; // Schedule for car

public:
    Car(string brand, string model, string color, string VIN, int year, int mileage, int price_per_day, int deposit); // Constructor
    Car();                                                                                                            // Constructor
    void addSchedule(ScheduleForCar schedule);                                                                        // Add schedule
    void deleteSchedule(ScheduleForCar schedule);                                                                     // Delete schedule
    void showSchedule();                                                                                              // Show schedule
    void showCar();                                                                                                   // Show car
    void updateMileage();                                                                                             // Update mileage
    void updatePrice();                                                                                               // Update price
    void updateDeposit();                                                                                             // Update deposit
};

class Client
{
private:
    string name;                       // Name
    string surname;                    // Surname
    string date_of_birth;              // Date of birth
    string passport_number;            // Passport number
    string passport_expiration_date;   // Passport expiration date
    string phone_number;               // Phone number
    string email;                      // Email
    string address;                    // Address
    set<ScheduleForCustomer> schedule; // Schedule for customer

public:
    Client(string name, string surname, string date_of_birth, string passport_number, string passport_expiration_date, string phone_number, string email, string address); // Constructor
    Client();                                                                                                                                                              // Constructor
    void addSchedule(ScheduleForCustomer schedule);                                                                                                                        // Add schedule
    void deleteSchedule(ScheduleForCustomer schedule);                                                                                                                     // Delete schedule
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
    void showSchedule();                                                                          // Show schedule
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

class ScheduleForCustomer : public Schedule
{
private:
    Car *car; // Car

public:
    ScheduleForCustomer(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to, Car *car); // Constructor
    ScheduleForCustomer();                                                                                             // Constructor
    void showScheduleForCustomer();                                                                                    // Show schedule for customer
};

#endif // CLASSES_HPP