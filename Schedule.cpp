#include "classes.hpp"

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