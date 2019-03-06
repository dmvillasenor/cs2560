#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee{
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    Employee(string n, int i, string d, string p){
        name = n;
        idNumber = i;
        department = d;
        position = p;
    }
    Employee(string n, int i){
        name = n;
        idNumber = i;
        department = "";
        position = "";

    }
    Employee(){
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }
    string getName(){
        string n = name;
        return n;
    }
    int getID(){
        int id = idNumber;
        return id;
    }
    string getDepart(){
        string depart = department;
        return depart;

    }
    string getPosition(){
        string pos = position;
        return pos;
    }
    void setName(string n){
        name = n;
    }
    void setID(int i){
        idNumber = i;
    }
    void setDepart(string d){
        department = d;
    }
    void setPosition(string p){
        position = p;
    }

};

int main(void){

    Employee employee1 ("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee employee2 ("Mark Jones", 39119, "IT", "Programmer");
    Employee employee3 ("Joy Rogers", 81774, "Manufacturing", "Engineer");

    //Employees put in array for use in a for loop
    Employee employees[3] = {employee1, employee2, employee3};

    //Print Column Headers
    cout << left << setw(15)<<"Name:"
                 << setw(11)<< "ID:"
                 << setw(17) << "Department:"
                 << setw(20) << "Position:"
                 << endl;

    for(int i = 0; i < 3; i++){
        cout << left << setw(15) << employees[i].getName()
                     << setw(11)  << employees[i].getID()
                     << setw(17)  << employees[i].getDepart()
                     << setw(20)  << employees[i].getPosition()
                     << endl;
    }//end for
}// end main