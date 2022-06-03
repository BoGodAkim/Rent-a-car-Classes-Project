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

    rcs.rentCar(rcs.chooseClient("123"), rcs.chooseCar(0), schedule);
    rcs.rentCar(rcs.chooseClient("124"), rcs.chooseCar(1), schedule);
    rcs.rentCar(rcs.chooseClient("123"), rcs.chooseCar(1), schedule); // rent two cars with the same passport number in same time
    rcs.rentCar(rcs.chooseClient("124"), rcs.chooseCar(0), schedule); // rent car which is already rented
    schedule.fillSchedule(10, 5, 2022, 15, 6, 2022);
    rcs.rentCar(rcs.chooseClient("124"), rcs.chooseCar(0), schedule); // rent car which is already rented

    rcs.showCars();
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs.chooseClient("124")->showSchedule();
    cout << endl;

    rcs.deleteClient(rcs.chooseClient("123"));
    rcs.deleteCar(rcs.chooseCar(1));
    rcs.showCars();
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs.chooseClient("124")->showSchedule();
    cout << endl;

    rcs.rentCar(rcs.chooseClient("124"), rcs.chooseCar(0), schedule);
    rcs.showCars();

    rcs.deleteSchedule(rcs.chooseClient("124"), rcs.chooseCar(0), schedule);
    cout << "Schedule Clint with passport number 124:" << endl;
    rcs.chooseClient("124")->showSchedule();
    cout << endl;
    rcs.showCars();

    rcs.chooseCar(0)->updateMileage(1000);
    rcs.chooseCar(0)->updatePrice(1000);
    rcs.chooseCar(0)->updateDeposit(2000);
    rcs.chooseCar(0)->updateMileage(999); // update car with incorrect mileage
    rcs.chooseCar(0)->updatePrice(0);    // update car with incorrect price
    rcs.chooseCar(0)->updateDeposit(-1000); // update car with incorrect deposit   
    rcs.showCars();
}