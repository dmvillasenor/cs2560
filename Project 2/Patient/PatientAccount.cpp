#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class PatientAccount{
private:
    string pName;
    double totalCharges = 0;
    int daysInHospital = 0;
    double hospitalCharge = 15.50;


public:

    PatientAccount(string name) {
        pName = name;
        totalCharges = 0;
        daysInHospital = 0;
    }

    double getTotal(){
        return totalCharges;
    }

    void updateTotal(double charges){
        totalCharges += charges;
    }

    void setDays(){
        daysInHospital++;
    }

    double visitCost(){
        return hospitalCharge * daysInHospital;
    }

};