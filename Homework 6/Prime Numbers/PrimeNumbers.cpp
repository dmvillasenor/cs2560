#include <iostream>
#include <string>
#include <vector>


void isPrime(int i ){
    bool prime = true;
    for(int index = i -1; index > 1; index--){
        if( i % index == 0){
            prime = false;
            break;
        }
    }

    if(prime){
        std::cout << i << " ";
    }
}
int main(){
    std::vector<int> v1;

    int num;

    std::cout << "Enter a number" << std::endl;
    std::cin >> num;

    std::cout << "All prime numbers below " << num << " " << std::endl;
    for(int i = 2; i <= num; i++) {
        v1.push_back(i);
    }

    std::for_each( v1.begin(), v1.end(), isPrime);
}