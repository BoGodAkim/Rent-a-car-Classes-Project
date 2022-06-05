#include "classes.hpp"

Schedule::Schedule()
{
}

void Schedule::printSchedule() const
{
    cout << this->year_from << "." << this->month_from << "." << this->day_from << "-" << this->year_to << "." << this->month_to << "." << this->day_to << endl;
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

void Schedule::fillSchedule(int day_from, int month_from, int year_from, int day_to, int month_to, int year_to)
{
    if (!checkSchedule(year_from, month_from, day_from, year_to, month_to, day_to))
    {
        cout << "Wrong date" << endl;
        return;
    }
    this->day_from = day_from;
    this->month_from = month_from;
    this->year_from = year_from;
    this->day_to = day_to;
    this->month_to = month_to;
    this->year_to = year_to;
}

bool Schedule::operator<(const Schedule &schedule) const
{
    if (this->year_to <= schedule.year_from && this->month_to <= schedule.month_from && this->day_to < schedule.day_from)
        return true;
    else
        return false;
}

ScheduleForCar::ScheduleForCar()
{
}

ScheduleForCar::ScheduleForCar(const Schedule *schedule, Client *client)
{
    this->day_from = schedule->day_from;
    this->month_from = schedule->month_from;
    this->year_from = schedule->year_from;
    this->day_to = schedule->day_to;
    this->month_to = schedule->month_to;
    this->year_to = schedule->year_to;
    this->client = client;
}

void ScheduleForCar::showScheduleForCar()
{
    cout << "Day from: " << this->day_from << endl
         << "Month from: " << this->month_from << endl
         << "Year from: " << this->year_from << endl
         << "Day to: " << this->day_to << endl
         << "Month to: " << this->month_to << endl
         << "Year to: " << this->year_to << endl
         << endl;
}

void ScheduleForCar::deleteClientSchedule() const
{
    this->client->deleteSchedule(this);
}

ScheduleForClient::ScheduleForClient()
{
}

ScheduleForClient::ScheduleForClient(const Schedule *schedule, Car *car)
{
    this->day_from = schedule->day_from;
    this->month_from = schedule->month_from;
    this->year_from = schedule->year_from;
    this->day_to = schedule->day_to;
    this->month_to = schedule->month_to;
    this->year_to = schedule->year_to;
    this->car = car;
}

void ScheduleForClient::showScheduleForClient()
{
    cout << "Day from: " << this->day_from << endl
         << "Month from: " << this->month_from << endl
         << "Year from: " << this->year_from << endl
         << "Day to: " << this->day_to << endl
         << "Month to: " << this->month_to << endl
         << "Year to: " << this->year_to << endl
         << endl;
}

void ScheduleForClient::deleteCarSchedule() const
{
    this->car->deleteSchedule(this);
}