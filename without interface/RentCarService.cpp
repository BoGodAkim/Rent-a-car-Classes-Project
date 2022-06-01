#include "classes.hpp"
#include <bits/stdc++.h>

RentCarService::RentCarService()
{
}

void RentCarService::addCar(string brand, string model, string color, string VIN, int year, int mileage, float price_per_day, int deposit)
{
    if (year < 1900 || year > 2022)
    {
        cout << "Wrong year!" << endl;
        return;
    }
    if (mileage <= 0)
    {
        cout << "Wrong mileage!" << endl;
        return;
    }
    if (deposit <= 0)
    {
        cout << "Wrong deposit!" << endl;
        return;
    }
    if (price_per_day <= 0)
    {
        cout << "Wrong price per day!" << endl;
        return;
    }
    cars.push_back(new Car(brand, model, color, VIN, year, mileage, price_per_day, deposit));
}

void RentCarService::addClient(string name, string surname, string date_of_birth, string passport_number, string phone_number, string email, string address)
{
    if(clients.find(passport_number) != clients.end())
    {
        cout << "Client with this passport number already exists!" << endl;
        return;
    }
    clients[passport_number] = new Client(name, surname, date_of_birth, passport_number, phone_number, email, address);
}

bool operator<(const Schedule &a, const Schedule &b)
{
    // if (a.year_to <= b.year_from && a.month_to <= b.month_from && a.day_to < b.day_from)
    //     return true;
    // else
    //     return false;
    if (a.year_to * 366 + a.month_to * 31 + a.day_to < b.year_from * 366 + b.month_from * 31 + b.day_from)
        return true;
    else
        return false;
}

bool operator>(const Schedule &a, const Schedule &b)
{
    // if (b.year_to <= a.year_from && b.month_to <= a.month_from && b.day_to < a.day_from)
    //     return true;
    // else
    //     return false;
    if (b < a)
        return true;
    else
        return false;
}

void printSchedule(const Schedule &a)
{
    cout << a.year_from << "." << a.month_from << "." << a.day_from << "-" << a.year_to << "." << a.month_to << "." << a.day_to << endl;
}

void RentCarService::rentCar(Client *client, Car *car, Schedule schedule)
{
    ScheduleForCar scheduleForCar(&schedule, client);
    ScheduleForClient scheduleForClient(&schedule, car);
    if(client->getSchedule()->find(scheduleForClient) != client->getSchedule()->end())
        cout << "This client already has a car in this time";
    if(car->getSchedule()->find(scheduleForCar) != car->getSchedule()->end())
        cout << "This car already has a client in this time";
    client->addSchedule(&scheduleForClient);
    car->addSchedule(&scheduleForCar);
}

void RentCarService::showCars()
{
    int i = 1;
    for (auto car = cars.begin(); car != cars.end(); car++)
    {
        cout << "Number: " << i << endl;
        i++;
        (*car)->showCar();
    }
    cout << endl;
}

void RentCarService::deleteCar(Car *car)
{
    cars.erase(remove(cars.begin(), cars.end(), car), cars.end());
}

void RentCarService::deleteClient(Client *client)
{
    clients.erase(remove(clients.begin(), clients.end(), client), clients.end());
}

void RentCarService::deleteSchedule(Client *client, Car *car, Schedule schedule)
{
    ScheduleForCar scheduleForCar(&schedule, client);
    ScheduleForClient scheduleForClient(&schedule, car);
    client->getSchedule()->erase(scheduleForClient);
    car->getSchedule()->erase(scheduleForCar);
}

Car *RentCarService::chooseCar(int index)
{
    if(index < 0 || index >= cars.size())
        return nullptr;
    return cars[index];
}

Client *RentCarService::chooseClient(string passport_number)
{
    if(clients.find(passport_number) == clients.end())
    {
        cout << "Client with this passport number doesn't exist!" << endl;
        return nullptr;
    }
    return clients[passport_number];
}
