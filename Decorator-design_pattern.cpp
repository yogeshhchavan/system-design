#include<iostream>
#include<string>

using namespace std;

// component interface: defines a common interface for Mario and al power-up decorators.
class Character {
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {} // virtual destructor
};

// concrete Componenet: Basic Mario character with nopower-ups.
class Mario : public Character {
public:
    string getAbilities() const override {
        return "Mario";
    }
};

// Abstract Decorator: ConcreateDecorator"is-a" Character and "has-a" Character.
class CharacterDecorator : public Character {
protected:
    Character* character; // wrapped component
public:
    CharacterDecorator(Character* c){
        this->character = c;
    }
    // virtual ~CharacterDecorator() {
    //     delete character; // prevents memory leaks
    // }
};

// Concrete Decorator: Hight-Increasing Power-up.
class HeightUp : public CharacterDecorator{
public:
    HeightUp(Character* c) : CharacterDecorator(c){ }

    string getAbilities() const override {
        return character->getAbilities() + " with HeightUp";
    }
};

// Concreate Decorator: Gun Shooting Pow r-Up.
class GunPowerUp : public CharacterDecorator {
public: 
    GunPowerUp(Character* c) : CharacterDecorator(c){ }

    string getAbilities() const override {
        return character->getAbilities() + " with Gun";
    }
};

// Concrete Decorator: Star Power-Up (temporary ability).
class StarPowerUp : public CharacterDecorator {
public:
    StarPowerUp(Character* c) : CharacterDecorator(c){ }

    string getAbilities() const override {
        return character->getAbilities() + " with Star Power (Limited Time)";
    }

    ~StarPowerUp(){
        cout<<"Destroying StarPowerUp Decorator"<<endl;
    }
};

int main(){
    // create a basic Mario character.
    Character* mario = new Mario();
    cout<<"Basic Character: "<<mario->getAbilities() << endl;    

    // Decorate Mario with a HeightUppower-up.
    mario = new HeightUp(mario);
    cout<<"After  HeightUp: "<< mario->getAbilities() << endl;

    // Decorate Mario with a GunPowerUp.
    mario = new GunPowerUp(mario);
    cout<<"After Gun Power-Up: "<< mario->getAbilities() << endl;

    // Finally, add a StarPowerUP decortion.
    mario = new StarPowerUp(mario);
    cout<<"After Star Power-Up: "<< mario->getAbilities() << endl;

    delete mario;
    return 0;
}





// =================================================================================

//                             OUTPUT

// =================================================================================

// Basic Character: Mario
// After  HeightUp: Mario with HeightUp
// After Gun Power-Up: Mario with HeightUp with Gun
// After Star Power-Up: Mario with HeightUp with Gun with Star Power (Limited Time)
// Destroying StarPowerUp Decorator

// =================================================================================
