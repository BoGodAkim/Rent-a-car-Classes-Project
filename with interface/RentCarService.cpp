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
        cout << endl;
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
    } while (mileage <= 0);
    do
    {
        cout << "Enter price per day: ";
        getline(cin, value);
        price_per_day = stof(value);
    } while (price_per_day <= 0);
    do
    {
        cout << "Enter deposit: ";
        getline(cin, value);
        deposit = stoi(value);
    } while (deposit <= 0);
    cars.push_back(new Car(brand, model, color, VIN, year, mileage, price_per_day, deposit));
    cout << endl;
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
    cout << endl;
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

void RentCarService::deleteRentSchedule()
{
    Client *client = chooseClient();
    client->deleteSchedule();
}

void RentCarService::showCars()
{
    int i = 1;
    for (auto car = cars.begin(); car != cars.end(); car++)
    {
        cout << "Number: " << i <<endl;
        i++;
        (*car)->showCar();
    }
    cout << endl;
}

void RentCarService::returnCar()
{
    Client *client = chooseClient();
    client->deleteSchedule();
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
    cout << endl;
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
    cout << endl;
    return cars[choice - 1];
}

Client *RentCarService::chooseClient()
{
    // TODO:
    string choice = "\n\n\n";
    while (clients.find(choice) == clients.end())
    {
        cout << "Enter passport number: ";
        getline(cin, choice);
        if (choice == "")
        {
            this->addClient();
        }
        if (clients.find(choice) == clients.end())
        {
            cout << "Wrong passport number!" << endl;
        }
    }
    cout << endl;
    return clients[choice];
}
