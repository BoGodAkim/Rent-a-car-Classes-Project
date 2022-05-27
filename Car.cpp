#include "classes.hpp"

Car::Car()
{
}

Car::Car(string brand, string model, string color, string VIN, int year, int mileage, int price_per_day, int deposit)
{
    this->brand = brand;
    this->model = model;
    this->color = color;
    this->VIN = VIN;
    this->year = year;
    this->mileage = mileage;
    this->price_per_day = price_per_day;
    this->deposit = deposit;
}

void Car::addSchedule(ScheduleForCar *schedule)
{
    this->schedule.insert(*schedule);
}

void Car::deleteSchedule(const Schedule *schedule)
{
    for (auto it = this->schedule.begin(); it != this->schedule.end(); it++)
    {
        if (*it == *schedule)
        {
            this->schedule.erase(it);
            break;
        }
    }
}

void Car::showSchedule()
{
    for (auto it = this->schedule.begin(); it != this->schedule.end(); it++)
    {
        printSchedule(*it);
    }
}

void Car::showCar()
{
    cout << "Brand: " << this->brand << endl
         << "Model: " << this->model << endl
         << "Color: " << this->color << endl
         << "VIN: " << this->VIN << endl
         << "Year: " << this->year << endl
         << "Mileage: " << this->mileage << endl
         << "Price per day: " << this->price_per_day << endl
         << "Deposit: " << this->deposit << endl;
}

void Car::updateMileage()
{
    string value;
    int mileage;
    do
    {
        cout << "Enter mileage: ";
        getline(cin, value);
        mileage = stoi(value);
    } while (mileage < this->mileage);
    this->mileage = mileage;
}

void Car::updatePrice()
{
    string value;
    int price_per_day;
    do
    {
        cout << "Enter price per day: ";
        getline(cin, value);
        price_per_day = stoi(value);
    } while (price_per_day <= 0);
    this->price_per_day = price_per_day;
}

void Car::updateDeposit()
{
    string value;
    int deposit;
    do
    {
        cout << "Enter deposit: ";
        getline(cin, value);
        deposit = stoi(value);
    } while (deposit <= 0);
    this->deposit = deposit;
}

set<ScheduleForCar> *Car::getSchedule()
{
    return &(this->schedule);
}
