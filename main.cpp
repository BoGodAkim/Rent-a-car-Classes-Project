#include <bits/stdc++.h>

using namespace std;

#include "classes.hpp"

RentCarService::RentCarService()
{
}

void RentCarService::enterMenu()
{
    while (true)
    {
        int option;
        string value;
        cout << "1. Add car" << endl;
        cout << "2. Add client" << endl;
        cout << "3. Rent car" << endl;
        cout << "4. Delete rent schedule" << endl;
        cout << "5. Show cars" << endl;
        cout << "6. Return car" << endl;
        cout << "7. Update car" << endl;
        cout << "8. Delete car" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter option: ";
        getline(cin, value);
        option = stoi(value);
        switch (option)
        {
        case 1:
            addCar();
            break;
        case 2:
            addClient();
            break;
        case 3:
            rentCar();
            break;
        case 4:
            deleteRentSchedule();
            break;
        case 5:
            showCars();
            break;
        case 6:
            returnCar();
            break;
        case 7:
            updateCar();
            break;
        case 8:
            deleteCar();
            break;
        case 9:
            return;
            break;
        default:
            cout << "Wrong option!" << endl;
            break;
        }
        enterMenu();
    }
}

void RentCarService::addCar()
{
    string value;
    string brand;
    string model;
    string color;
    string VIN;
    int year;
    int mileage;
    float price_per_day;
    int deposit;
    cout << "Enter brand: ";
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter color: ";
    getline(cin, color);
    cout << "Enter VIN: ";
    getline(cin, VIN);
    do
    {
        cout << "Enter year: ";
        getline(cin, value);
        year = stoi(value);
    } while (year < 1900 || year > 2022);
    do
    {
        cout << "Enter mileage: ";
        getline(cin, value);
        mileage = stoi(value);
    } while (mileage < 0);
    do
    {
        cout << "Enter price per day: ";
        getline(cin, value);
        price_per_day = stof(value);
    } while (price_per_day < 0);
    do
    {
        cout << "Enter deposit: ";
        getline(cin, value);
        deposit = stoi(value);
    } while (deposit < 0);
    cars.push_back(new Car(brand, model, color, VIN, year, mileage, price_per_day, deposit));
}

void RentCarService::addClient()
{
    string name;
    string surname;
    string date_of_birth;
    string passport_number;
    string phone_number;
    string email;
    string address;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter surname: ";
    getline(cin, surname);
    cout << "Enter date of birth: ";
    getline(cin, date_of_birth);
    cout << "Enter passport number: ";
    getline(cin, passport_number);
    cout << "Enter phone number: ";
    getline(cin, phone_number);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter address: ";
    getline(cin, address);
    clients[passport_number] = new Client(name, surname, date_of_birth, passport_number, phone_number, email, address);
}

bool operator<(const Schedule &a, const Schedule &b)
{
    if (a.year_to <= b.year_from && a.month_to <= b.month_from && a.day_to < b.day_from)
        return true;
    else
        return false;
}

bool operator>(const Schedule &a, const Schedule &b)
{
    if (b.year_to <= a.year_from && b.month_to <= a.month_from && b.day_to < a.day_from)
        return true;
    else
        return false;
}

bool operator==(const Schedule &a, const Schedule &b)
{
    if (a.year_to <= b.year_from && a.month_to <= b.month_from && a.day_to < b.day_from && a.year_to >= b.year_from && a.month_to >= b.month_from && a.day_to >= b.day_from)
        return true;
    else if (b.year_to <= a.year_from && b.month_to <= a.month_from && b.day_to < a.day_from && b.year_to >= a.year_from && b.month_to >= a.month_from && b.day_to >= a.day_from)
        return true;
    else
        return false;
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
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day_from < 1 || day_from > 31)
            return false;
        break;
    case 4:
    case 6:
    case 9:
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
    case 1:if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 3:if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 5:if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 7:if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 8:if (day_to < 1 || day_to > 31)
            return false;
        break;
    case 10:if (day_to < 1 || day_to > 31)
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
            cout << "Rent successful!" << endl;
        }
    } while (!flag);
}

void RentCarService::deleteRentSchedule()
{
    Client *client = chooseClient();
    client->deleteSchedule();
}

void RentCarService::showCars()
{
    for (auto car = cars.begin(); car != cars.end(); car++)
    {
        (*car)->showCar();
    }
}

void RentCarService::returnCar()
{
    // TODO:
}

void RentCarService::updateCar()
{
    string value;
    int choice = 0;
    Car *car = chooseCar();
    while (choice == 0)
    {
        cout << "1. Update mileage" << endl
             << "2. Update price per day" << endl
             << "3. Update deposit" << endl
             << "Enter option: ";
        getline(cin, value);
        choice = stoi(value);
        switch (choice)
        {
        case 1:
            car->updateMileage();
            break;
        case 2:
            car->updatePrice();
            break;
        case 3:
            car->updateDeposit();
            break;
        default:
            cout << "Wrong option!" << endl;
            choice = 0;
            break;
        }
    }
}

void RentCarService::deleteCar()
{
    Car *car = chooseCar();
    cars.erase(remove(cars.begin(), cars.end(), car), cars.end());
}

Car *RentCarService::chooseCar()
{
    this->showCars();
    string value;
    int choice = 0;
    while (choice < 1 || choice > cars.size())
    {
        cout << "Enter car number: ";
        getline(cin, value);
        choice = stoi(value);
    }
    return cars[choice - 1];
}

Client *RentCarService::chooseClient()
{
    string choice = "\n\n\n";
    while (clients.find(choice) == clients.end())
    {
        cout << "Enter passport number: ";
        getline(cin, choice);
        if (clients.find(choice) == clients.end())
        {
            cout << "Wrong passport number!" << endl;
        }
    }
    return clients[choice];
}

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

Client::Client()
{
}

Client::Client(string name, string surname, string date_of_birth, string passport_number, string phone_number, string email, string address)
{
    this->name = name;
    this->surname = surname;
    this->date_of_birth = date_of_birth;
    this->passport_number = passport_number;
    this->phone_number = phone_number;
    this->email = email;
    this->address = address;
}

void Client::addSchedule(ScheduleForClient *schedule)
{
    this->schedule.insert(*schedule);
}

void Client::deleteSchedule()
{
    this->showSchedule();
    string value;
    int choice = 0;
    while (choice < 1 || choice > this->schedule.size())
    {
        cout << "Enter schedule number: ";
        getline(cin, value);
        choice = stoi(value);
    }
    for (auto it = this->schedule.begin(); it != this->schedule.end(); it++)
    {
        choice--;
        if (choice == 0)
        {
            it->car->deleteSchedule(&(*it));
            this->schedule.erase(it);
            break;
        }
    }
}

void Client::showSchedule()
{
    int i = 0;
    for (auto it = this->schedule.begin(); it != this->schedule.end(); it++)
    {
        printSchedule(*it);
        i++;
    }
}

void Client::showClient()
{
    cout << "Name: " << this->name << endl
         << "Surname: " << this->surname << endl
         << "Date of birth: " << this->date_of_birth << endl
         << "Passport number: " << this->passport_number << endl
         << "Phone number: " << this->phone_number << endl
         << "Email: " << this->email << endl
         << "Address: " << this->address << endl;
}

set<ScheduleForClient> *Client::getSchedule()
{
    return &(this->schedule);
}

Schedule::Schedule()
{
}

Schedule::Schedule(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to)
{
    this->day_from = day_from;
    this->month_from = month_from;
    this->year_from = year_from;
    this->day_to = day_to;
    this->month_to = month_to;
    this->year_to = year_to;
}

bool Schedule::operator<(const Schedule &schedule)
{
    if (this->year_to <= schedule.year_from && this->month_to <= schedule.month_from && this->day_to < schedule.day_from)
        return true;
    else
        return false;
}

ScheduleForCar::ScheduleForCar()
{
}

ScheduleForCar::ScheduleForCar(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to, Client *client)
{
    this->day_from = day_from;
    this->month_from = month_from;
    this->year_from = year_from;
    this->day_to = day_to;
    this->month_to = month_to;
    this->year_to = year_to;
    this->client = client;
}

void ScheduleForCar::showScheduleForCar()
{
    cout << "Day from: " << this->day_from << endl
         << "Month from: " << this->month_from << endl
         << "Year from: " << this->year_from << endl
         << "Day to: " << this->day_to << endl
         << "Month to: " << this->month_to << endl
         << "Year to: " << this->year_to << endl;
}

ScheduleForClient::ScheduleForClient()
{
}

ScheduleForClient::ScheduleForClient(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to, Car *car)
{
    this->day_from = day_from;
    this->month_from = month_from;
    this->year_from = year_from;
    this->day_to = day_to;
    this->month_to = month_to;
    this->year_to = year_to;
    this->car = car;
}

void ScheduleForClient::showScheduleForClient()
{
    cout << "Day from: " << this->day_from << endl
         << "Month from: " << this->month_from << endl
         << "Year from: " << this->year_from << endl
         << "Day to: " << this->day_to << endl
         << "Month to: " << this->month_to << endl
         << "Year to: " << this->year_to << endl;
}

int main()
{
    RentCarService rcs;
    rcs.enterMenu();
}