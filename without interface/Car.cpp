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

void Car::deleteSchedule(Schedule *schedule)
{
    ScheduleForCar schedule_for_car(schedule, nullptr);
    this->schedule.erase(schedule_for_car);
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
         << "Deposit: " << this->deposit << endl
         << "Schedule: " << endl;
    this->showSchedule();
    cout << endl;
}

void Car::updateMileage(int mileage)
{
    if (mileage > this->mileage)
    {
        this->mileage = mileage;
    }
    else
    {
        cout << "Mileage must be larger then before" << endl;
    }
}

void Car::updatePrice(int price_per_day)
{
    if(price_per_day < 1)
    {
        cout << "Price per day must be larger then 0" << endl;
    }
    else
    {
        this->price_per_day = price_per_day;
    }
}


void Car::updateDeposit(int deposit)
{
    if(deposit < 1)
    {
        cout << "Deposit must be larger then 0" << endl;
    }
    else
    {
        this->deposit = deposit;
    }
}

set<ScheduleForCar> *Car::getSchedule()
{
    return &(this->schedule);
}
