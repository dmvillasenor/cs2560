#include <iostream>
#include <string>

class Employee{
    std::string empName;
    int empNum;
    int hireDate;

    Employee() { };
public:
    Employee(std::string name, int num, int date) :
                empName(name), empNum(num), hireDate(date){
        if(empNum < 0 || empNum > 9999){
            std::string exceptionString = "InvalidEmployeeNumber";
            throw exceptionString;
        }
    }
    int getEmpNum(){
        return empNum;
    }

    int getHireDate(){
        return hireDate;
    }

    std::string getEmpName(){
        return empName;
    }
};

class ProductionWorker : public Employee{
    int shift;
    double payRate;

public:
    ProductionWorker(std::string name, int num, int date, int sh, double pay) :
                        Employee( name, num, date), shift(sh), payRate(pay){
        if(shift != 1 && shift != 0){
            std::string exceptionString = "InvalidShift";
            throw exceptionString;
        }

        if(payRate < 0){
            std::string exceptionString = "InvalidPayRate";
            throw exceptionString;
        }
    }

    int getShift(){
        return shift;
    }

    double getPay(){
        return payRate;
    }
};

int main(){
    try{
        ProductionWorker worker("Hello", -1, 0112201, -2, -11.5);
    }
    catch(std::string exceptionString ){
        std::cout << exceptionString << std::endl;
    }

    try{
        ProductionWorker worker("Hello", 1, 0112201, -2, -11.5);
    }
    catch(std::string exceptionString ){
        std::cout << exceptionString << std::endl;
    }

    try{
        ProductionWorker worker("Hello", 1, 0112201, 1, -11.5);
    }
    catch(std::string exceptionString ){
        std::cout << exceptionString << std::endl;
    }

}