#include "classes.hpp"

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
    cout << endl;
}

void Client::showSchedule()
{
    int i = 1;
    for (auto it = this->schedule.begin(); it != this->schedule.end(); it++)
    {
        cout << "Number: " << i << endl;
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
         << "Address: " << this->address << endl
         << endl;
}

set<ScheduleForClient> *Client::getSchedule()
{
    return &(this->schedule);
}