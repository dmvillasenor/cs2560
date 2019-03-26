#include <iostream>



class PersonData {
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    int zip;
    int phone;

    PersonData();

public:
    PersonData(std::string ln, std::string fn, std::string add, std::string c, std::string s, int z, int p) :
                lastName(ln), firstName(fn), address(add), city(c), state(s), zip(z), phone(p) {
        printf("PersonData Constructed\n");
    }

    void setLastName(std::string name) {
        lastName = name;
    }

    void setFirstName(std::string name) {
        firstName = name;
    }

    void setAddress(std::string name) {
        address = name;
    }

    void setCity(std::string name) {
        city = name;
    }

    void setState(std::string name) {
        state = name;
    }

    void setZip(int name) {
        zip = name;
    }

    void setPhone(int name) {
        phone = name;
    }

    std::string getLastName(){
        return lastName;
    }

    std::string getFirstName(){
        return firstName;
    }

    std::string getAddress(){
        return address;
    }

    std::string getCity(){
        return city;
    }

    std::string getState(){
        return state;
    }

    int getZip(){
        return zip;
    }

    int getPhone(){
        return phone;
    }

};

class CustomerData : public PersonData {
    int customerNumber;
    bool mailingList;
public:
    CustomerData( int cNum, bool mList, std::string ln, std::string fn,
                  std::string add, std::string c, std::string s, int z, int p) :
                  PersonData(ln, fn, add, c, s, z, p),customerNumber(cNum), mailingList(mList){
        printf("CustomerData constructed\n");
    }

    void setCustomerNum( int n ){
        customerNumber = n;
    }

    void setMailList( bool mList){
        mailingList = mList;
    }

    int getCustomerNum(){
        return customerNumber;
    }

    bool getMailList(){
        return mailingList;
    }

};

int main() {
    CustomerData customer(123, true, "Obama", "Barack", "12345 Box Street", "Boxville", "Boxifornia", 12345, 1234567890);

    std::string list = "No";
    if(customer.getMailList()){
        list = "Yes";
    }

    std::cout << "First: " << customer.getFirstName() << std::endl
              << "Last: " << customer.getLastName() << std::endl
              << "Address: " << customer.getAddress() << std::endl
              << "City: " << customer.getCity() << std::endl
              << "State: " << customer.getState() << std::endl
              << "Zip: " << customer.getZip() << std::endl
              << "Phone #: " << customer.getPhone() << std::endl
              << "Customer #: " << customer.getCustomerNum() << std::endl
              << "On Mail List: "<< list << std::endl;

    return 0;

}