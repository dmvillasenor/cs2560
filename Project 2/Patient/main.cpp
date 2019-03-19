#include <iostream>
#include <string>
#include <iomanip>

#include "Pharmacy.cpp"

using namespace std;


int validInput();

int main(){
    PatientAccount patient("Joe Biden");
    bool checkedOut = false;
    Surgery surgeries( 1);
    Pharmacy pharmacy( 1);


    while(!checkedOut){
        int input = validInput();

        switch(input){
            case 1:
                patient = surgeries.getSurgery(patient);
                patient.setDays();
                break;
            case 2:
                patient.setDays();
                patient = pharmacy.getMeds(patient);
                break;
            case 3:
                checkedOut = true;
                break;

            default:
                printf("");
                break;
        }

    }
    patient.updateTotal(patient.visitCost());
    cout << "Joe Biden owes: $" << patient.getTotal() << endl;
    return 0;
}

void printMenu(){
    cout <<"1. Get Surgery" << endl
         <<"2. Get Medication" << endl
         <<"3. Check Out" << endl;
}
int validInput(){
    int input;
    bool valid = false;
    while(!valid){

        printMenu();
        cin >> input;
        if(input > 0 && input < 4 ){
            valid = true;
        }

    }
    return input;
}