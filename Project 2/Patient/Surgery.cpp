#include <iostream>
#include <string>
#include <iomanip>
#include "PatientAccount.cpp"

using namespace std;

class Surgery {
private:

    double heartTransplant = 5.50;
    double brainTransplant = 10.50;
    double apendixRemoval = 15.50;
    double handAmputation = 20.50;
    double legAmputation = 25.50;
    int test;

    void printMenu2() {
        cout << "1. Heart Transplant" << endl
             << "2. Brain Transplant" << endl
             << "3. Apendix Removal" << endl
             << "4. Hand Amputation" << endl
             << "5. Leg Amputation" << endl;
    }

    int validInputTwo() {
        int input;
        bool valid = false;
        while (!valid) {

            printMenu2();
            cin >> input;
            if (input > 0 && input < 6) {
                valid = true;
            }

        }
        return input;
    }


public:

    Surgery(int t){
        test = t;
    }
    Surgery(){
        Surgery(0);
    }
    PatientAccount getSurgery(PatientAccount patient2) {

        int input = validInputTwo();

        switch (input) {
            case 1:
                patient2.updateTotal(heartTransplant);
                break;
            case 2:
                patient2.updateTotal(brainTransplant);
                break;
            case 3:
                patient2.updateTotal(apendixRemoval);
                break;
            case 4:
                patient2.updateTotal(handAmputation);
                break;
            case 5:
                patient2.updateTotal(legAmputation);
                break;
            default:
                patient2.updateTotal(0);
                break;
        }
        return patient2;
    }
};
