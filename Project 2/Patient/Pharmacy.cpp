#include <iostream>
#include <string>
#include <iomanip>
#include "Surgery.cpp"

using namespace std;


class Pharmacy{
private:
    double heartMeds = 5.25;
    double painkillers = 3.25;
    double sleepMeds = 2.25;
    double ibuprofen = 6.25;
    double advil = 7.25;
    int test;

    void printMenu3() {
        cout << "1. Heart Medication" << endl
             << "2. Painkillers" << endl
             << "3. Sleep Medication" << endl
             << "4. Ibuprofen" << endl
             << "5. Advil" << endl;
    }

    int validInputThree() {
        int input;
        bool valid = false;
        while (!valid) {

            printMenu3();
            cin >> input;
            if (input > 0 && input < 6) {
                valid = true;
            }

        }
        return input;
    }

public:

    Pharmacy(int t){
        test = t;
    }
    Pharmacy(){
        Surgery(0);
    }
    PatientAccount getMeds(PatientAccount patient2) {

        int input = validInputThree();

        switch (input) {
            case 1:
                patient2.updateTotal(heartMeds);
                break;
            case 2:
                patient2.updateTotal(painkillers);
                break;
            case 3:
                patient2.updateTotal(sleepMeds);
                break;
            case 4:
                patient2.updateTotal(ibuprofen);
                break;
            case 5:
                patient2.updateTotal(advil);
            default:
                patient2.updateTotal(0);
                break;
        }
        return patient2;
    }
};
