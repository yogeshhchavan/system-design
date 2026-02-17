#include<iostream>
#include<string>
using namespace std;

class SportCar {  
private: 
        //Characters........
        string brand;
        string model;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;
        string tyre;

public:
        SportCar(string b, string m){  // Constructor
            this->brand = b;           
            this->model = m;
            this->isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            tyre = "MRF";

        }

        // getter / setter methods
        int getCurrentSpeed() {
            return this->currentSpeed;
        }

        string getTyre() {
            return this->tyre;
        }

        void setTyre(string tyre) {
            // validation
            this->tyre = tyre;
        }

        // behaviors --> Methods 
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
    SportCar* mySportsCar = new SportCar("Foard", "Mustang GT");
    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelarate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelarate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    // setting arbitrary value to speed.
    // mySportsCar->currentSpeed = 500;
    
    // cout<<"Current speed of my sports car is set to "<<mySportsCar->currentSpeed<<endl;
    
    cout<<mySportsCar->getCurrentSpeed()<<endl; // using getter method to access current speed of the car.
    
    delete mySportsCar;
    return 0;
}



// ==============================================================================
//                                   OUTPUT
// ==============================================================================
//                       Foard Mustang GT : Engine starts with a roar!
//                       Foard Mustang GT : Shifted to Gear 1
//                       Foard Mustang GT : Accelerating to: 20 km/h
//                       Foard Mustang GT : Shifted to Gear 2
//                       Foard Mustang GT : Accelerating to: 40 km/h
//                       Foard Mustang GT : Braking!  Speed is now 20 km/h
//                       Foard Mustang GT : Engine turn Off.

// ==============================================================================
