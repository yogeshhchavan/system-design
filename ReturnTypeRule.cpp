#include<iostream>
using namespace std;

// returnn type Rule:
// Subtype overriding method return type should be either identical
//or narrower then the parent method return type
// this is also called as return type covriance.
// C++ enforce this by convriance.

class Animal{
    // some common Animal method
};

class Dog : public Animal{
    //Additional dog method specific to Dog
};

class Parent{
public:
    virtual Animal* getAnimal(){
        cout<<"parent : returning Animal instance" << endl;
        return new Animal();
    }
};

class Child : public Parent{
public:
    Dog* getAnimal() override {
        cout<<"Child : returning Dog instance" << endl;
        return new Dog();
    }
};

class Client{
private:
    Parent* p;
public:
    Client(Parent* p){
        this->p = p;
    }

    void takeAnimal(){
        p->getAnimal();
    }
};

int main(){
    Parent* parent = new Parent();
    Child* child = new Child();
    Client* client = new Client(child);
    client->takeAnimal();
    return 0;
}