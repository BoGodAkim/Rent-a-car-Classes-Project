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

bool operator==(const Schedule &a, const Schedule &b)
{
    // NOTE:
    // if (a.year_to <= b.year_to && a.month_to <= b.month_to && a.day_to < b.day_to && a.year_to >= b.year_from && a.month_to >= b.month_from && a.day_to >= b.day_from)
    //     return true;
    // else if (b.year_to <= a.year_to && b.month_to <= a.month_to && b.day_to < a.day_to && b.year_to >= a.year_from && b.month_to >= a.month_from && b.day_to >= a.day_from)
    //     return true;
    // else
    //     return false;
    if ((!(a < b)) && (!(b < a)))
        return true;
    else
        return false;

    // if(a.year_to*366+a.month_to*31+a.day_to >= b.year_from*366+b.month_from*31+b.day_from && a.year_to*366+a.month_to*31+a.day_to <= b.year_to*366+b.month_to*31+b.day_to)
    //     return true;
    // else if (b.year_to*366+b.month_to*31+b.day_to >= a.year_from*366+a.month_from*31+a.day_from && b.year_to*366+b.month_to*31+b.day_to <= a.year_to*366+a.month_to*31+a.day_to)
    //     return true;
    // else
    //     return false;
}

void printSchedule(const Schedule &a)
{
    cout << a.year_from << "." << a.month_from << "." << a.day_from << "-" << a.year_to << "." << a.month_to << "." << a.day_to << endl;
}

bool checkSchedule(int year_from, int month_from, int day_from, int year_to, int month_to, int day_to)
{
    if (year_from < 2022)
        return false;
    if (month_from < 1 || month_from > 12)
        return false;
    switch (month_from)
    {
    case 1:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 3:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 5:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 7:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 8:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 10:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 12:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 4:
        if (day_from < 1 || day_from > 30)
            return false;
        break;
    case 6:
        if (day_from < 1 || day_from > 30)
            return false;
        break;
    case 9:
        if (day_from < 1 || day_from > 30)
            return false;
        break;
    case 11:
        if (day_from < 1 || day_from > 30)
            return false;
        break;
    case 2:
        if (year_from % 4 == 0)
        {
            if (day_from < 1 || day_from > 29)
                return false;
        }
        else
        {
            if (day_from < 1 || day_from > 28)
                return false;
        }
        break;
    }
    if (year_to < year_from)
        return false;
    if (month_to < 1 || month_to > 12)
        return false;
    switch (month_to)
    {
    case 1:
        if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 3:
        if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 5:
        if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 7:
        if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 8:
        if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 10:
        if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 12:
        if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 4:
        if (day_to < 1 || day_to > 30)
            return false;
        break;
    case 6:
        if (day_to < 1 || day_to > 30)
            return false;
        break;
    case 9:
        if (day_to < 1 || day_to > 30)
            return false;
        break;
    case 11:
        if (day_to < 1 || day_to > 30)
            return false;
        break;
    case 2:
        if (year_to % 4 == 0)
        {
            if (day_to < 1 || day_to > 29)
                return false;
        }
        else
        {
            if (day_to < 1 || day_to > 28)
                return false;
        }
        break;
    }
    if (year_to * 366 + month_to * 31 + day_to < year_from * 366 + month_from * 31 + day_from)
        return false;
    return true;
}

void RentCarService::rentCar()
{
    // FIXME:
    Client *client = chooseClient();
    Car *car = chooseCar();
    auto it1 = client->getSchedule()->begin();
    auto it2 = car->getSchedule()->begin();
    while (it1 != client->getSchedule()->end() && it2 != car->getSchedule()->end())
    {
        if (*it1 < *it2)
        {
            printSchedule(*it1);
            it1++;
        }
        else if (*it1 > *it2)
        {
            printSchedule(*it2);
            it2++;
        }
        else
        {
            if (it1->year_from <= it2->year_from && it1->month_from <= it2->month_from && it1->day_from <= it2->day_from)
            {
                printSchedule(*it1);
                it1++;
            }
            else
            {
                printSchedule(*it2);
                it2++;
            }
        }
    }
    while (it1 != client->getSchedule()->end())
    {
        printSchedule(*it1);
        it1++;
    }
    while (it2 != car->getSchedule()->end())
    {
        printSchedule(*it2);
        it2++;
    }
    bool flag = true;
    do
    {
        flag = true;
        int year_from, month_from, day_from;
        int year_to, month_to, day_to;
        do
        {
            cout << "Enter rent date in format yyyy.mm.dd-yyyy.mm.dd: ";
            string value;
            getline(cin, value);
            year_from = stoi(value.substr(0, 4));
            month_from = stoi(value.substr(5, 2));
            day_from = stoi(value.substr(8, 2));
            year_to = stoi(value.substr(11, 4));
            month_to = stoi(value.substr(16, 2));
            day_to = stoi(value.substr(19, 2));
        } while (!checkSchedule(year_from, month_from, day_from, year_to, month_to, day_to));
        Schedule schedule(year_from, month_from, day_from, year_to, month_to, day_to);
        auto it1 = client->getSchedule()->begin();
        auto it2 = car->getSchedule()->begin();
        while (it1 != client->getSchedule()->end())
        {
            if (*it1 == schedule)
            {
                cout << "This schedule is already taken!" << endl;
                flag = false;
            }
            it1++;
        }
        while (it2 != car->getSchedule()->end())
        {
            if (*it2 == schedule)
            {
                cout << "This schedule is already taken!" << endl;
                flag = false;
            }
            it2++;
        }
        if (flag)
        {
            ScheduleForCar scheduleForCar(day_from, month_from, year_from, day_to, month_to, year_to, client);
            ScheduleForClient scheduleForClient(day_from, month_from, year_from, day_to, month_to, year_to, car);
            client->addSchedule(&scheduleForClient);
            car->addSchedule(&scheduleForCar);
        }
    } while (!flag);
    cout << endl;
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
