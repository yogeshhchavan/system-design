// static polymorphism in C++: A simple example of static polymorphism using function overloading and operator overloading.

#include<iostream>
#include<string>
using namespace std;

class ManualCar {
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear; // specific to Manual Car

public:
    ManualCar(string brand, string model) {
            this->brand = brand;
            this->model = model;
            this->isEngineOn = false;
            this->currentSpeed = 0;
            this->currentGear = 0;
        }

    // common method for All Cars.
    void startEngine() {
            isEngineOn = true;
            cout<< brand <<" "<<model<<" : Engine started."<<endl;
        }
    void stopEngine() {
            isEngineOn = false;
            currentSpeed = 0;
            cout<< brand <<" "<<model<<" : Engine turn Off."<<endl;
        }

   //overloading accelarate - static Polymorphism
    void accelarate() {
        if(!isEngineOn){
            cout<< brand <<" "<< model <<" : Cannot Accelerate! Engine is Off!  "<<endl;
            return;
        }
        currentSpeed += 20;
        cout<< brand <<" "<< model <<" : Accelerating to: "<<currentSpeed<<" km/h"<<endl;        
        } 

    void accelarate(int speed) { // Overloaded method for faster acceleration
        if(!isEngineOn){
            cout<< brand <<" "<< model <<" : Cannot Accelerate! Engine is Off!  "<<endl;
            return;
        }
        currentSpeed += speed;
        cout<< brand <<" "<< model <<" : Accelerating to: "<<currentSpeed<<" km/h"<<endl;        
        }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0)  currentSpeed = 0;
        cout<< brand <<" "<< model <<" : Braking! Current Speed: "<<currentSpeed<<" km/h"<<endl;
    }

    void shiftGear(int gear) { // Overloaded method to shift to a specific gear
        currentGear = gear;
        cout<< brand <<" "<< model <<" : Shifted to Gear "<<currentGear<<endl;
    }
};

// main function
int main() {
    ManualCar myManualCar("SUZUKI", "WAGNOR");
    myManualCar.startEngine();
    myManualCar.accelarate();
    myManualCar.accelarate(40); // Using overloaded method for faster acceleration
    myManualCar.brake();
    myManualCar.stopEngine();

    //clean up
    delete &myManualCar; // Deleting the object to free memory

    return 0;
}


// ==============================================================================================================================
//                                                               OUTPUT
// ==============================================================================================================================
//                                                           SUZUKI WAGNOR : Engine started.
//                                                           SUZUKI WAGNOR : Accelerating to: 20 km/h
//                                                           SUZUKI WAGNOR : Accelerating to: 60 km/h
//                                                           SUZUKI WAGNOR : Braking! Current Speed: 40 km/h
//                                                           SUZUKI WAGNOR : Engine turn Off.

// ==============================================================================================================================
