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

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Basic Wheat Burger with wheat bun, patty, and ketchup!"<<endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Standard Wheat Burger with wheat bun, patty, cheese, and lettuce!"<<endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Premium Wheat Burger with wheat bun, patty, cheese, lettuce, tomato, and special sauce!"<<endl;
    }
}; 


// FACTORY and CONNECTION
class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0; // Pure virtual function for creating burgers
};

class SinghBurger : public BurgerFactory {
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


class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicWheatBurger();
        }
        else if(type == "standard"){
            return new StandardWheatBurger();
        }
        else if(type == "premium"){
            return new PremiumWheatBurger();
        }
        else{
            cout<<"Invalid Burger type........!"<<endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "basic";

    BurgerFactory* myFactory = new KingBurger();
    Burger* burger = myFactory->createBurger(type);
    burger->prepare();

    return 0;
}


// ============================================================================================

//                                           OUTPUT

// =============================================================================================

//                 Preparing Basic Wheat Burger with wheat bun, patty, and ketchup!

// =============================================================================================
