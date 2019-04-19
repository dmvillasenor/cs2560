#include <iostream>
#include <string>
#include <vector>


class Human{
    std::string name;
    int age;
    char sex;

    Human(){ }
protected:
    Human(std::string n, int a, char s) : name(n), age(a), sex(s){
        //std::cout << "Human constructed" << std::endl;
    }

    virtual ~Human(){
        //std::cout << "Human Deconstructed" << std::endl;
    }

public:


    void setAge(int a){
        age = a;
    }

    void setName(std::string n) {
        name = n;
    }

    void setSex(char s){
        sex = s;
    };

    std::string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    char getSex(){
        return sex;
    }


};

class Child : public Human{
    std::string momName, dadName;
    int allowance;

    Child(): Human("", 0, 0){ }
public:
    Child(std::string n, int a, char s, std::string dName, std::string mName) :
            Human(n, a, s), momName(mName), dadName(dName), allowance(0){
        //std::cout << "Child constructed" << std::endl;
    }

    virtual ~Child(){
        //std::cout << "Child Deconstructed" << std::endl;
    }

    int getAllowance() const {
        std::cout << "Allowance: " << allowance << std::endl;
        return allowance;
    }

    void setAllowance(int allow) {
        allowance = allow;
    }

    void printParent(){
        std::cout << "Mom's name: " << momName << std::endl
                  << "Dad's name: " << dadName << std::endl;
    }
};



void printName(std::string name){
    std::cout << name << std::endl;
}

class Parent : public Human{

    std::vector<std::string> children;

    Parent() : Human("", 0, 0){ }

    bool containsChild(std::string name){
        bool containChild = false;
        for(int i = 0; i < children.size(); i++){
            if(name == children[i]){
                containChild = true;
            }
        }
        return containChild;
    }
public:

    Parent(std::string n, int a, char s) :
            Human(n, a, s){
        //std::cout << "Parent constructed" << std::endl;
    }

    virtual ~Parent(){
        //std::cout << "Parent deconstructed" << std::endl;
    }

    void printChild(){
        std::for_each( children.begin(), children.end(), printName);
    }

    void setChild(Child c){
        children.push_back(c.getName());
    }

    void setChildAllowance(int allowance, Child & c){
        if( containsChild(c.getName())){
            c.setAllowance(allowance);
        }
    }

};


void printInfo(Human & h){
    std::cout << "Name: " << h.getName() << std::endl
              << "Age: " << h.getAge() << std::endl
              << "Sex: " << h.getSex() << std::endl;
}

int main() {


    Parent homer("Homer", 36, 'M');
    Parent march("March", 34, 'F');

    Child lisa("Lisa", 12, 'F', "Homer", "March");
    Child bart("Bart", 10, 'M', "Homer", "March");
    Child maggie("Maggie", 3, 'F', "Homer", "March");

    homer.setChild(lisa);
    homer.setChild(bart);
    homer.setChild(maggie);

    march.setChild(lisa);
    march.setChild(maggie);
    march.setChild(bart);

    bart.getAllowance();

    homer.setChildAllowance(5, bart);

    bart.getAllowance();

    bart.printParent();

    printInfo( march);
    printInfo(lisa);



    return 0;
}