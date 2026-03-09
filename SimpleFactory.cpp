#include<iostream>
using namespace std;

class Burger {
public:
    virtual void prepare() =0; // Pure virtual function for preparing the burger
    virtual ~Burger() {} // virtual destructor for proper cleanup

};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Basic Burger with bun, patty, and ketchup!"<<endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Standard Burger with bun, patty, cheese, and lettuce!"<<endl;
    }
};

class PremimumBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Premium Burger with bun, patty, cheese, lettuce, tomato, and special sauce!"<<endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "premium"){
            return new PremimumBurger();
        }
        else{
            cout<<"Invalid Burger type........!"<<endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->prepare();

    return 0;
}



// // =====================================================================|
//                                                                         |
// //                               OUTPUT                                 |
//                                                                         |
// // =====================================================================|
//                                                                         |
//                                                                         |
// //      Preparing Standard Burger with bun, patty, cheese, and lettuce! |
//                                                                         |
//                                                                         |
// // =====================================================================|
