#include <bits/stdc++.h>

using namespace std;

#include "RentCarService.cpp"
#include "Car.cpp"
#include "Client.cpp"
#include "Schedule.cpp"
#include "classes.hpp"

int main()
{
    RentCarService rcs;
    rcs.addCar("BMW", "X5", "Black", "VIN", 2019, 100, 100, 1000);
    rcs.addCar("Audi", "A4", "White", "VIN", 2020, 200, 200, 2000);
    rcs.addCar("Mercedes", "C class", "Red", "VIN", 2021, 300, 300, 3000);
    rcs.addCar("Toyota", "Corolla", "Blue", "VIN", 2023, 400, 400, 4000); // add car with incorrect year
    rcs.addCar("Ford", "Focus", "Green", "VIN", 2020, -12, 500, 5000);    // add car with incorrect mileage
    rcs.addCar("BMW", "X5", "Black", "VIN", 2019, 100, -100, 1000);       // add car with incorrect price
    rcs.addCar("Audi", "A4", "White", "VIN", 2020, 200, 200, -2000);      // add car with incorrect deposit

    rcs.addClient("John", "Smith", "01.01.2000", "123", "+48578951235", "johnsmith@gmail.com", "Warsaw");
    rcs.addClient("Mike", "Smith", "01.01.2000", "124", "+48578951235", "mikesmith@gmail.com", "Warsaw");
    rcs.addClient("John", "Smith", "01.01.2000", "123", "+48578951235", "johnsmith@gmail.com", "Warsaw"); // add client with incorrect passport number

    Schedule schedule;
    schedule.fillSchedule(10, 10, 2022, 19, 1, 2022); // add schedule with incorrect data
    schedule.fillSchedule(36, 9, 2022, 20, 10, 2022); // add schedule with incorrect data
    schedule.fillSchedule(10, 6, 2022, 10, 7, 2022);

    rcs.rentCar(0, "123", schedule);
    rcs.rentCar(1, "124", schedule);
    rcs.rentCar(1, "123", schedule); // rent two cars with the same passport number in same time
    rcs.rentCar(0, "124", schedule); // rent car which is already rented
    schedule.fillSchedule(10, 5, 2022, 15, 6, 2022);
    rcs.rentCar(0, "124", schedule); // rent car which is already rented

    rcs.showCars();
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs.showClient("124");
    cout << endl;

    rcs.deleteClient("123");
    rcs.deleteCar(1);
    rcs.showCars();
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs.showClient("124");
    cout << endl;

    rcs.rentCar(0, "124", schedule);
    rcs.showCars();

    rcs.deleteSchedule(0, "124", schedule);
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs.showClient("124");
    cout << endl;
    rcs.showCars();

    rcs.carUpdateMilage(0, 1000);
    rcs.carUpdatePrice(0, 1000);
    rcs.carUpdateDeposit(0, 2000);
    rcs.carUpdateMilage(0, 999);           // update car with incorrect mileage
    rcs.carUpdatePrice(0, 0);              // update car with incorrect price
    rcs.carUpdateDeposit(0, -1000);        // update car with incorrect deposit
    rcs.showCars();

    RentCarService *rcs2 = new RentCarService();
    rcs2->addCar("BMW", "X5", "Black", "VIN", 2019, 100, 100, 1000);
    rcs2->addCar("Audi", "A4", "White", "VIN", 2020, 200, 200, 2000);
    rcs2->addCar("Mercedes", "C class", "Red", "VIN", 2021, 300, 300, 3000);
    rcs2->addCar("Toyota", "Corolla", "Blue", "VIN", 2023, 400, 400, 4000); // add car with incorrect year
    rcs2->addCar("Ford", "Focus", "Green", "VIN", 2020, -12, 500, 5000);    // add car with incorrect mileage
    rcs2->addCar("BMW", "X5", "Black", "VIN", 2019, 100, -100, 1000);       // add car with incorrect price
    rcs2->addCar("Audi", "A4", "White", "VIN", 2020, 200, 200, -2000);      // add car with incorrect deposit

    rcs2->addClient("John", "Smith", "01.01.2000", "123", "+48578951235", "johnsmith@gmail.com", "Warsaw");
    rcs2->addClient("Mike", "Smith", "01.01.2000", "124", "+48578951235", "mikesmith@gmail.com", "Warsaw");
    rcs2->addClient("John", "Smith", "01.01.2000", "123", "+48578951235", "johnsmith@gmail.com", "Warsaw"); // add client with incorrect passport number

    schedule.fillSchedule(10, 10, 2022, 19, 1, 2022); // add schedule with incorrect data
    schedule.fillSchedule(36, 9, 2022, 20, 10, 2022); // add schedule with incorrect data
    schedule.fillSchedule(10, 6, 2022, 10, 7, 2022);

    rcs2->rentCar(0, "123", schedule);
    rcs2->rentCar(1, "124", schedule);
    rcs2->rentCar(1, "123", schedule); // rent two cars with the same passport number in same time
    rcs2->rentCar(0, "124", schedule); // rent car which is already rented
    schedule.fillSchedule(10, 5, 2022, 15, 6, 2022);
    rcs2->rentCar(0, "124", schedule); // rent car which is already rented

    rcs2->showCars();
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs2->showClient("124");
    cout << endl;

    rcs2->deleteClient("123");
    rcs2->deleteCar(1);
    rcs2->showCars();
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs2->showClient("124");
    cout << endl;

    rcs2->rentCar(0, "124", schedule);
    rcs2->showCars();

    rcs2->deleteSchedule(0, "124", schedule);
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs2->showClient("124");
    cout << endl;
    rcs2->showCars();

    rcs2->carUpdateMilage(0, 1000);
    rcs2->carUpdatePrice(0, 1000);
    rcs2->carUpdateDeposit(0, 2000);
    rcs2->carUpdateMilage(0, 999);    // update car with incorrect mileage
    rcs2->carUpdatePrice(0, 0);       // update car with incorrect price
    rcs2->carUpdateDeposit(0, -1000); // update car with incorrect deposit
    rcs2->showCars();
}