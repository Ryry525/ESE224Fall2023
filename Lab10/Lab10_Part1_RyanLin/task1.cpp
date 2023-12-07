#include <iostream>

using namespace std;

class CEAS{
public:
    CEAS();
    virtual void displayInfo();
    virtual void requrements();
    virtual void printCores();
};

class ECE : public CEAS{
public:
    ECE();
    void displayInfo();
    void printCores();
};

class ESE : public CEAS{
public:
    ESE();
    void displayInfo();
    void printCores();
};

CEAS::CEAS() {};
ESE::ESE() {};
ECE::ECE() {};

void CEAS::displayInfo(){
    cout << endl;
    cout << "CEAS students need..." << endl;
}
void ECE::displayInfo(){
    cout << endl;
    cout << "ECE students need..." << endl;
}
void ESE::displayInfo(){
    cout << endl;
    cout << "ESE suents need..." << endl;
}

void CEAS::requrements(){
    cout << "Req1: Completion of at least 120 credit hours of passing work" <<endl;
    cout << "Req2: A minimum cumlative grade point average of 2.00" << endl;
}

void CEAS::printCores() {}
void ECE::printCores(){
    cout << "ECE Core1: Computer Architecture" << endl;
    cout << "ECE Core2: Real-Time OS" << endl;
    cout << "ECE Core3: VHDL" << endl;
}
void ESE::printCores(){
    cout << "ESE Core1: Electromagnetic and Transmission Line theory" << endl;
    cout << "ESE Core2: Control System" << endl;
    cout << "ESE Core3: Advanced Electronic Laboratory" << endl;
}

void displayInfo(CEAS* p){p->displayInfo();}
void printRequirements(CEAS* p){p->requrements();}
void printCores(CEAS* p){p->printCores();}

int main(){
    CEAS ceasStudent;
    displayInfo(&ceasStudent);
    printRequirements(&ceasStudent);
    printCores(&ceasStudent);
    cout << "------------------------------------------------------------" << endl;
    ESE eseStudent;
    displayInfo(&eseStudent);
    printRequirements(&eseStudent);
    printCores(&eseStudent);
    cout << "------------------------------------------------------------" << endl;
    ECE eceStudent;
    displayInfo(&eceStudent);
    printRequirements(&eceStudent);
    printCores(&eceStudent);

    return 0;
}