

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class floatingPoints {
private:
    int size;
    float* array;
    int numOfEntries = 0;

public:
    floatingPoints(int n ){
        size = n;
        array = new float[n];
    }

    void setNum(float num){
        array[numOfEntries] = num;
        numOfEntries++;
    }

    float getNum(int index){
        if(index >= size) {
            cout << "Index is out of bounds" << endl;
            return -1;
        } else{
            return array[index];
        }
    }
    float highNum(){
        float hNum = 0;

        for( int i = 0; i < numOfEntries; i++){
            if(array[i] > hNum){
                hNum = array[i];
            }
        }
        return hNum;
    }
    float lowNum(){
        float lNum = array[0];

        for( int i = 1; i < numOfEntries; i++){
            if(array[i] < lNum){
                lNum = array[i];
            }
        }
        return lNum;
    }
};

int main(void) {
    floatingPoints array(10);
    array.setNum(12.0);
    array.setNum(11.9);
    array.setNum(13.0);
    array.setNum(5.9);

    cout << array.highNum() << endl;
    cout << array.lowNum() << endl;

    return 0;
}