#include "classes.hpp"

Client::Client()
{
}

Client::~Client()
{
    for (auto it = this->schedule.begin(); it != this->schedule.end(); ++it)
    {
        Schedule schedule = *it;
        it->deleteCarSchedule();
    }
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

void Client::deleteSchedule(const Schedule *schedule)
{
    ScheduleForClient schedule_for_car(schedule, nullptr);
    this->schedule.erase(schedule_for_car);
}

void Client::showSchedule()
{
    int i = 1;
    for (auto it = this->schedule.begin(); it != this->schedule.end(); it++)
    {
        cout << "Number: " << i << endl;
        it->printSchedule();
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
    this->showSchedule();
    cout << endl;
}

bool Client::checkSchedule(ScheduleForClient schedule)
{
    return this->schedule.find(schedule) != this->schedule.end();
}

string Client::getPassportNumber()
{
    return this->passport_number;
}