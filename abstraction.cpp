// This is the simple example of Abstraction in OOPs.

#include<iostream>
#include<string>
using namespace std;

// Real Life Car

class Car {  // Abstract Base Class
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear( int gear) = 0;
        virtual void accelarate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}   // Virtual Destructor
};

class SportCar : public Car {   // Derived Class (inheritance)
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;

        SportCar(string b, string m){  // Constructor
            this->brand = b;           
            this->model = m;
            this->isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;

        }

        void startEngine(){
            isEngineOn = true;
            cout<< brand <<" "<<model<<" : Engine starts with a roar!"<<endl;
        }

        void shiftGear(int gear){
            if (!isEngineOn) {
                cout<< brand <<" "<< model << " : Engine is Off! Cannot Shift Gear"<<endl;
                return;
            }
            currentGear = gear;
            cout<< brand << " "<< model <<" : Shifted to Gear "<<currentGear<<endl;
        }  

        void accelarate(){
            if (!isEngineOn) {
                cout<< brand <<" "<< model <<" : Engine is Off! Cannot Accelerate "<<endl;
                return;
            } 

            currentSpeed += 20;
            cout<< brand <<" "<< model <<" : Accelerating to: "<<currentSpeed<<" km/h"<<endl;
        }

        void brake() {
            currentSpeed -= 20;
            if (currentSpeed < 0)  currentSpeed = 0;
            cout<< brand <<" "<< model <<" : Braking!  Speed is now "<<currentSpeed<<" km/h"<<endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout<< brand <<" "<< model <<" : Engine turn Off."<<endl;
        }
};

// Main Method

int main() {
    Car* myCar = new SportCar("Foard", "Mustang GT");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelarate();
    myCar->shiftGear(2);
    myCar->accelarate();
    myCar->brake();
    myCar->stopEngine();
    delete myCar;
    return 0;
}


// =================================================================================================================
//                                               OUTPUT
// =================================================================================================================
//                                             Foard Mustang GT : Engine starts with a roar!
//                                             Foard Mustang GT : Shifted to Gear 1
//                                             Foard Mustang GT : Accelerating to: 20 km/h
//                                             Foard Mustang GT : Shifted to Gear 2
//                                             Foard Mustang GT : Accelerating to: 40 km/h
//                                             Foard Mustang GT : Braking!  Speed is now 20 km/h
//                                             Foard Mustang GT : Engine turn Off.

// ==================================================================================================================
