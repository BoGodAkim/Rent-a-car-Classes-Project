#include "classes.hpp"
#include <bits/stdc++.h>

RentCarService::RentCarService()
{
}

RentCarService::~RentCarService()
{
    for(auto it = cars.begin(); it != cars.end(); it++)
    {
        delete *it;
    }
    for(auto it = clients.begin(); it != clients.end(); it++)
    {
        delete it->second;
    }
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
    if (clients.find(passport_number) != clients.end())
    {
        cout << "Client with this passport number already exists!" << endl;
        return;
    }
    clients[passport_number] = new Client(name, surname, date_of_birth, passport_number, phone_number, email, address);
}

void RentCarService::rentCar(int index, string passport_number, Schedule schedule)
{
    Client *client = chooseClient(passport_number);
    if (client == nullptr)
    {
        cout << "Client with this passport number doesn't exist!" << endl;
        return;
    }
    Car *car = chooseCar(index);
    if (car == nullptr)
    {
        cout << "Car with this index doesn't exist!" << endl;
        return;
    }
    ScheduleForCar scheduleForCar(&schedule, client);
    ScheduleForClient scheduleForClient(&schedule, car);
    if (client->checkSchedule(scheduleForClient))
    {
        cout << "This client already has a car in this time!" << endl;
        return;
    }
    if (car->checkSchedule(scheduleForCar))
    {
        cout << "This car already has a client in this time!" << endl;
        return;
    }

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

void RentCarService::deleteCar(int index)
{
    Car *car = chooseCar(index);
    if (car == nullptr)
    {
        cout << "Car with this index doesn't exist!" << endl;
        return;
    }
    cars.erase(remove(cars.begin(), cars.end(), car), cars.end());
    delete car;
}

void RentCarService::deleteClient(string passport_number)
{
    Client *client = chooseClient(passport_number);
    if (client == nullptr)
    {
        cout << "Client with this passport number doesn't exist!" << endl;
        return;
    }
    clients.erase(client->getPassportNumber());
    delete client;
}

void RentCarService::deleteSchedule(int index, string passport_number, Schedule schedule)
{
    Client *client=chooseClient(passport_number);
    if (client == nullptr)
    {
        cout << "Client with this passport number doesn't exist!" << endl;
        return;
    }
    Car *car = chooseCar(index);
    if (car == nullptr)
    {
        cout << "Car with this index doesn't exist!" << endl;
        return;
    }
    ScheduleForCar scheduleForCar(&schedule, client);
    ScheduleForClient scheduleForClient(&schedule, car);
    client->deleteSchedule(&scheduleForClient);
    car->deleteSchedule(&scheduleForCar);
}

void RentCarService::showClient(string passport_number)
{
    Client *client = chooseClient(passport_number);
    if (client == nullptr)
    {
        cout << "Client with this passport number doesn't exist!" << endl;
        return;
    }
    client->showClient();
}

void RentCarService::showCar(int index)
{
    Car *car = chooseCar(index);
    if (car == nullptr)
    {
        cout << "Car with this index doesn't exist!" << endl;
        return;
    }
    car->showCar();
}

void RentCarService::carUpdateDeposit(int index, int deposit)
{
    Car *car = chooseCar(index);
    if (car == nullptr)
    {
        cout << "Car with this index doesn't exist!" << endl;
        return;
    }
    car->updateDeposit(deposit);
}

void RentCarService::carUpdatePrice(int index, float price)
{
    Car *car = chooseCar(index);
    if (car == nullptr)
    {
        cout << "Car with this index doesn't exist!" << endl;
        return;
    }
    car->updatePrice(price);
}

void RentCarService::carUpdateMilage(int index, int mileage)
{
    Car *car = chooseCar(index);
    if (car == nullptr)
    {
        cout << "Car with this index doesn't exist!" << endl;
        return;
    }
    car->updateMileage(mileage);
}

Car *RentCarService::chooseCar(int index)
{
    if (index < 0 || index >= cars.size())
        return nullptr;
    return cars[index];
}

Client *RentCarService::chooseClient(string passport_number)
{
    if (clients.find(passport_number) == clients.end())
    {
        cout << "Client with this passport number doesn't exist!" << endl;
        return nullptr;
    }
    return clients[passport_number];
}
