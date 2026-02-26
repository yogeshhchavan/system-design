#include<iostream>
using namespace std;

// Exception Rule:
// A Subclass should throw fewer or narrower exception
// (but not additional or brother exception) than the parent.
// C++ does nto enforces this. Hence no compilationerror.


/*  std :: logic_error   <-- For logical errors detected before runtime 
        std :: invalid_argument     <-- Invalid function argument
        std :: domain_error         <-- Function argument domain error
        std: : length_error         <-- Exceeding valid length limits
        std :: out_of_range         <-- Array or container index out of bounds
    
    std: : runtime_error    <-- For errors detected during runtime
        std: : range_error          <-- Arithmetic overflow
        std :: overflow_error       <-- Arithmetic overflow 
        std :: underflow_error          */

class Parent{
public:
    virtual void getValue() noexcept(false){  // parent throws logic_error exception
        throw logic_error("Parent exception");

    }
};

class Child: public Parent{
public:
void getValue() noexcept(false) override{ // Child throws out_of_range exception
        throw out_of_range("Child exception");
    }
}; 

class Client{
private:
    Parent* p;
public:
    Client(Parent* p){
        this->p = p;
    }

    void takeValue(){
        try{
            p->getValue();
        }
        catch(const logic_error& e){
            cout<<"Logic error exception occured : "<<e.what()<<endl;
        }
    }
};

int main(){
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);
    client->takeValue();
    return 0;

}