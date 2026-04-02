#include<iostream>
using namespace std;

// Subsystems
class PowerSupply {
public:
    void providePower(){
        cout<<"Power Supply: Providing Power...."<<endl;
    }
};

class CoolingSystem {
public:
    void startfans(){
        cout<<"Cooling System: Fanstarted...."<<endl;
    }
};

class CPU {
public:
    void initialize() {
        cout<<"CPU: Initializing started...."<<endl;
    }
};

class Memory{
public:
    void selfTest(){
        cout<<"Memory: Self-test passed...."<<endl;
    }
};

class HardDrive {
public:
    void spinUp(){
        cout<<"Hard Drive: Spinning up......"<<endl;
    }
};

class BIOS {
public:
    void boot(CPU& cpu, Memory& memory){
        cout<<"BIOS: Booting CPU and Memory checks...."<<endl;
        cpu.initialize();
        memory.selfTest();
    }
};

class OperatingSystem {
public:
    void load(){
        cout<<"Operating System: Loading into memory...."<<endl;
    }
};

//Facade
class ComputerFacade {
private:    
    PowerSupply PowerSupply;
    CoolingSystem CoolingSystem;
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    BIOS bios;
    OperatingSystem os;
public:
    void startComputer(){
        cout<<"----- Starting Computer -----"<<endl;
        PowerSupply.providePower();
        CoolingSystem.startfans();
        bios.boot(cpu, memory);
        hardDrive.spinUp();
        os.load();
        cout<<"Computer Booted Successfully!"<<endl;
    }
};

//client
int main(){
    ComputerFacade computer;
    computer.startComputer();

    return 0;

}




// ====================================================
//                     OUTPUT
// ====================================================
//         BIOS: Booting CPU and Memory checks....
//         CPU: Initializing started....
//         Memory: Self-test passed....
//         Hard Drive: Spinning up......
//         Operating System: Loading into memory....
//         Computer Booted Successfully!
// =====================================================
