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
    vector<Car *> cars;                           // Vector of cars
    map<string, Client *> clients;                // Map of clients with their passport number as key
    Car *chooseCar(int index);                    // Choose car from the vector using function Car::showCar() and ask for the number of the car from the manager
    Client *chooseClient(string passport_number); // Choose client: ask for the passport number of the client and return the pointer to the client

public:
    void addCar(string brand, string model, string color, string VIN, int year, int mileage, float price_per_day, int deposit);                   // Add a car to the vector with parameters 
    void addClient(string name, string surname, string date_of_birth, string passport_number, string phone_number, string email, string address); // Add client to the map with parameters 
    void rentCar(int index, string passport_number, Schedule schedule);                                                                           // This function call Car* chooseCar() and Client* chooseClient() and rent the car to the client with the given schedule
    void showCars();                                                                                                                              // Show cars all cars in the vector using function Car::showCar()
    void showClient(string passport_number);                                                                                                      // Show client with this passport number using function Client::showClient()
    void showCar(int index);                                                                                                                      // Show car with this index using function Car::showCar()
    void deleteCar(int index);                                                                                                                    // Delete car call Car* chooseCar()
    void deleteClient(string passport_number);                                                                                                    // Delete client call Client* chooseClient()
    void deleteSchedule(int index, string passport_number, Schedule schedule);                                                                    // Call Car* chooseCar() and Client* chooseClient() and delete the schedule with the given parameters
    void carUpdateMilage(int index, int mileage);                                                                                                 // Update car mileage call Car* chooseCar()
    void carUpdatePrice(int index, float price_per_day);                                                                                          // Update car price call Car* chooseCar()
    void carUpdateDeposit(int index, int deposit);                                                                                                // Update car deposit call Car* chooseCar()
    RentCarService();                                                                                                                             // Constructor
    ~RentCarService();                                                                                                                            // Destructor
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
    ~Car();                                                                                                           // Destructor
    void addSchedule(ScheduleForCar *schedule);                                                                       // Add schedule to the set schedule 
    void deleteSchedule(const Schedule *schedule);                                                                    // Delete schedule
    void showSchedule();                                                                                              // Show schedule
    void showCar();                                                                                                   // Show car
    void updateMileage(int mileage);                                                                                  // Check if the mileage is greater than the current mileage and update the mileage
    void updatePrice(int price_per_day);                                                                              // Update price per day
    void updateDeposit(int deposit);                                                                                  // Update deposit
    bool checkSchedule(ScheduleForCar schedule);                                                                      // Check if the car is available for this schedule
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
    ~Client();                                                                                                                            // Destructor
    void addSchedule(ScheduleForClient *schedule);                                                                                        // Add schedule to the set schedule
    void deleteSchedule(const Schedule *schedule);                                                                                        // Delete schedule
    void showSchedule();                                                                                                                  // Show schedule
    void showClient();                                                                                                                    // Show client
    bool checkSchedule(ScheduleForClient schedule);                                                                                       // Check if the car is available for this schedule and return true if the car is available for this schedule
    string getPassportNumber();                                                                                                           // Return passport number
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
    void printSchedule() const;                                                                            // Print schedule
    bool operator<(const Schedule &other) const;                                                           // Operator <
    Schedule();                                                                                            // Constructor
    ~Schedule() = default;                                                                                 // Destructor
    void fillSchedule(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to); // Fill schedule
    friend class ScheduleForClient;
    friend class ScheduleForCar;
};

class ScheduleForCar : public Schedule
{
private:
    Client *client; // Client

public:
    ScheduleForCar(const Schedule *schedule, Client *client); // Constructor
    ScheduleForCar();                                         // Constructor
    ~ScheduleForCar() = default;                              // Destructor
    void showScheduleForCar();                                // Show schedule for car
    void deleteClientSchedule() const;                        // Delete client schedule
};

class ScheduleForClient : public Schedule
{
private:
    Car *car; // Car

public:
    ScheduleForClient(const Schedule *schedule, Car *car); // Constructor
    ScheduleForClient();                                   // Constructor
    ~ScheduleForClient() = default;                        // Destructor
    void showScheduleForClient();                          // Show schedule for customer
    void deleteCarSchedule() const;                        // Delete car schedule
};

#endif // CLASSES_HPP