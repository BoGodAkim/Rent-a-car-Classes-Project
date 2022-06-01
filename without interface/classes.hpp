#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <bits/stdc++.h>

using std::map;
using std::set;
using std::string;
using std::vector;

class RentCarService;
class Car;
class Client;
class Schedule;
class ScheduleForClient;
class ScheduleForCar;

class RentCarService
{
private:
    vector<Car *> cars;                                                                                                                           // Vector of cars
    map<string, Client *> clients;                                                                                                                // Map of clients with their passport number as key
public:
    void addCar(string brand, string model, string color, string VIN, int year, int mileage, float price_per_day, int deposit);                   // Add a car to the vector with parameters from the manager
    void addClient(string name, string surname, string date_of_birth, string passport_number, string phone_number, string email, string address); // Add client to the map with parameters from the manager
    void rentCar(Client *client, Car *car, Schedule schedule);                                                                                    // This function call Car* chooseCar() and Client* chooseClient(), ask date period from manager and if can rent the car to the client using function Car::addSchedule() and Client::addSchedule()
    void showCars();                                                                                                                              // Show cars all cars in the vector using function Car::showCar()
    void deleteCar(Car *car);                                                                                                                     // Delete car call Car* chooseCar()
    void deleteClient(Client *client);
    void deleteSchedule(Client *client, Car *car, Schedule schedule);                                                                             // Delete client call Client* chooseClient()
    Car *chooseCar(int index);                                                                                                                    // Choose car from the vector using function Car::showCar() and ask for the number of the car from the manager
    Client *chooseClient(string passport_number);                                                                                                 // Choose client: ask for the passport number of the client and return the pointer to the client
    RentCarService();  // Constructor
    ~RentCarService(); // Destructor
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
    ~Car() = default;                                                                                                 // Destructor
    void addSchedule(ScheduleForCar *schedule);                                                                       // TODO:                                                                       // Add schedule to the set schedule if the car is available for this schedule and return true if the car is available for this schedule
    void deleteSchedule(Schedule *schedule);                                                                    // TODO:                                                                    // Delete schedule
    void showSchedule();                                                                                              // Show schedule
    void showCar();                                                                                                   // Show car
    void updateMileage(int mileage);                                                                                  // Update mileage ask manager to enter the new mileage which larger then before and update the mileage
    void updatePrice(int price_per_day);                                                                              // Update price ask manager to enter the new price and update the price
    void updateDeposit(int deposit);                                                                                  // Update deposit ask manager to enter the new deposit and update the deposit
    set<ScheduleForCar> *getSchedule();                                                                               // Get schedule
};

class Client
{
private:
    string name;                     // Name
    string surname;                  // Surname
    string date_of_birth;            // Date of birth
    string passport_number;          // Passport number
    string phone_number;             // Phone number
    string email;                    // Email
    string address;                  // Address
    set<ScheduleForClient> schedule; // Schedule for customer

public:
    Client(string name, string surname, string date_of_birth, string passport_number, string phone_number, string email, string address); // Constructor
    Client();                                                                                                                             // Constructor
    ~Client() = default;                                                                                                                  // Destructor
    void addSchedule(ScheduleForClient *schedule);                                                                                        // Add schedule to the set schedule if the car is available for this schedule and return true if the car is available for this schedule
    void deleteSchedule(Schedule *schedule);                                                                                              // TODO:                                                                                                                // Delete schedule: call showSchedule() and ask for the number of the schedule from the manager, call Car::deleteSchedule(ScheduleForClient schedule) and delete the schedule from the set schedule
    void showSchedule();                                                                                                                  // Show schedule
    void showClient();                                                                                                                    // Show client
    set<ScheduleForClient> *getSchedule();                                                                                                // Return pointer to the set schedule
};

class Schedule
{
public:
    int day_from;   // Day from
    int month_from; // Month from
    int year_from;  // Year from
    int day_to;     // Day to
    int month_to;   // Month to
    int year_to;    // Year to

public:
    bool operator<(const Schedule &other);                                                                 // Operator <
    Schedule();                                                                                            // Constructor
    ~Schedule() = default;                                                                                 // Destructor
    void fillSchedule(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to); // Fill schedule
};

class ScheduleForCar : public Schedule
{
public:
    Client *client; // Client

public:
    ScheduleForCar(Schedule *schedule, Client *client); // Constructor
    ScheduleForCar();                                   // Constructor
    ~ScheduleForCar() = default;                        // Destructor
    void showScheduleForCar();                          // Show schedule for car
};

class ScheduleForClient : public Schedule
{
public:
    Car *car; // Car

public:
    ScheduleForClient(Schedule *schedule, Car *car); // Constructor
    ScheduleForClient();                             // Constructor
    ~ScheduleForClient() = default;                  // Destructor
    void showScheduleForClient();                    // Show schedule for customer
};

#endif // CLASSES_HPP