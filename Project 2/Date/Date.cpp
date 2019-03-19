#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date{
private:
    int month;
    int day;
    int year;
    string getMonthString(int m ){
        switch(m){
            case 1:
                return "January";

            case 2:
                return "February";

            case 3:
                return "March";

            case 4:
                return "April";

            case 5:
                return "May";

            case 6:
                return "June";

            case 7:
                return "July";

            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12:
                return "December";
            default:
                return "";
        }
    }
public:
    Date(int m, int d, int y){
        if( m > 0 && m < 13){
            month = m;
        }
        else{
            cout << "Month out of range" << endl;
            month = 0;
        }
        if(d > 0 && d < 32 ) {
            day = d;
        }
        else{
            cout << "Day out of range" << endl;
            day = 0;
        }

        year = y;
    }
    Date(){
        Date(1, 1, 1);
    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;

    }
    int getYear(){
        return year;
    }

    void  setDay(int d){
        if( d < 32 && d > 0 ){
            day = d;
        }
        else{
            cout << "Day out of range" << endl;
        }

    }
    void setMonth(int m){
        if( m < 13 && m > 0){
            month = m;
        }
        else{
            cout << "Day out of range" << endl;
        }
    }
    void setYear(int y){
        year = y;
    }
    void printNumDate(){
        cout << month << "/" << day << "/" << year << endl;
    }
    void printStringUSDate(){
        cout << getMonthString(month) << " " << day << ", " << year << endl;
    }
    void printStringOtherDate(){
        cout << day << " " << getMonthString(month) << " " << year << endl;
    }

    void operator++(){

        ++day;
        if(day == 32){
            ++month;
            if( month == 13){
                month = 1;
                ++year;
            }
            day = 1;
        }
    }
    void operator++(int n){

        day++;
        if(day == 32){
            month++;
            if( month == 13){
                month = 1;
                year++;
            }
            day = 1;
        }
    }
    void operator--(){
        --day;
        if(day == 0 ) {
            --month;
            if (month == 0) {
                month = 12;
                --year;
            }
            day = 31;
        }
    }
    void operator--( int n){
        day--;
        if(day == 0 ) {
            month--;
            if (month == 0) {
                month = 12;
                year--;
            }
            day = 31;
        }
    }
    int operator-(Date one ){
        int between;
        int fdDays = ((month - 1) * 31) + day;
        int ldDays = ((one.getMonth() - 1) *  31 ) + one.getDay();
        if( fdDays >= ldDays){
            between = fdDays - ldDays;
        }
        else {
            between = ldDays - fdDays;
        }

        return between;
    }

    friend ostream &operator<<( ostream &output, Date one){
        cout << one.getMonthString(one.getMonth()) << " " << one.getDay() << ", " << one.getYear() << endl;
        return output;

    }
    friend istream &operator>>( istream &input, Date &one ){

        int d;
        int m;

        bool validInput = false;
        while(!validInput){
            cout << "Enter day, month, and year" << endl;
            input >>  d >> m >> one.year;
            if((d > 0 && d < 32) && ( m > 0 && m < 13 )){
                validInput = true;
            }// end if
            else{
                cout << "Day or month is out of range" << endl;
            }// end else

        }// end while
        one.day = d;
        one.month = m;


        return input;

    }


};
int main(){

    Date neww;
    cin >> neww;

    cout << neww << endl;

    neww--;
    cout << "Date post decremented:" << endl << neww << endl;


    --neww;
    cout << "Date pre decremented:" << endl << neww << endl;

    neww++;
    cout << "Date post incremented:" << endl << neww << endl;

    ++neww;
    cout << "Date pre incremented:" << endl << neww << endl;

}