#include <iostream>
#include <string>
using namespace std;


class Vehicle {
public:
   
    Vehicle(const string& make, const string& model, int year)
        : make(make), model(model), year(year) {}

     virtual void printDetails() const {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    
   

protected:
    string make;
    string model;
    int year;
};


class Car : public Vehicle {
public:
   
    Car(const string& make, const string& model, int year, int numSeats)
        : Vehicle(make, model, year), numSeats(numSeats) {}

    
    void printDetails() const override {
        Vehicle::printDetails();
        cout << "Number of Seats: " << numSeats << endl; 
    }

private:
    int numSeats;
};

class Truck : public Vehicle {
public:
    
    Truck(const string& make, const string& model, int year, double loadCapacity)
        : Vehicle(make, model, year), loadCapacity(loadCapacity) {}

    
    void printDetails() const override {
        Vehicle::printDetails();
        cout << "Load Capacity: " << loadCapacity << " tone" << endl; 
    }

private:
    double loadCapacity;
};

int main() {
    
    Car myCar("Mercedes", "C class", 2020, 5);
    myCar.printDetails(); 

    Truck myTruck("Volvo", "FH16(Am cautat pe net nu aveam idee :) )", 2021, 25);
    myTruck.printDetails();

    return 0;
}
