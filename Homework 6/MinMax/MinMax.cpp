#include <iostream>
#include <string>

template <typename T>
T minimum( const T & value1, const T & value2){
    if( value1 < value2 ){
        return value1;
    }
    else{
        return value2;
    }
}

template <typename T>
T maximum( const T & value1, const T & value2){
    if(value1 < value2){
        return value2;
    }
    else{
        return value1;
    }
}

int main(){
    int x = 8;
    int y = 10;

    std::cout << "Max & Min of Integers: 8 & 10" << std::endl
              << "Max: " << maximum<int>(x,y) << std::endl
              << "Min: " << minimum<int>(x,y) << std::endl;

    std::string string1 = "Hello";
    std::string string2 = "Bye";

    std::cout << "Max & Min of Strings: 'Hello' and 'Bye'" << std::endl
              << "Max: " << maximum<std::string>(string1, string2) << std::endl
              << "Min: " << minimum<std::string>(string1, string2) << std::endl;

}