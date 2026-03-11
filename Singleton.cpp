#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton(){
        cout<<"Singleton Constructor called, New Object created"<<endl;
    }
public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
        
};
Singleton* Singleton::instance = nullptr; // Initialize the static member variable

int main(){
    Singleton* st1 = Singleton::getInstance(); 
    Singleton* st2 = Singleton::getInstance();

    cout<<(st1 == st2)<<endl;
}



// ===========================================================================
//                             OUTPUT
// ===========================================================================

// Singleton Constructor called, New Object created
// 1

// ===========================================================================
