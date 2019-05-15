//
//  BigNumbers.cpp
//  BigNumbers
//
//  Created by Matthew Villasenor on 5/13/19.
//  Copyright © 2019 Matthew Villasenor. All rights reserved.
//


#include "BigNumbers.h"
#include <stdio.h>
#include <string>
#include <vector>
#include<iostream>
#include <iomanip>

//#include <stdexcept>

namespace BigNums{
    
    BigNumbers::BigNumbers(std::vector<long long int> number){
        longNum = number;
    }
    
    BigNumbers::BigNumbers(std::string num){
        std::vector<long long int> tempVector;
        int x = (int)num.length();
       
       // std::cout << num << std::endl;
        for(int i = x-1; i > -1; i--){
            
            std::string temp = num.substr(i, 1);
           // std::cout <<
            long long int x = std::stoll(temp);
            
            longNum.push_back(x);
            
        }
    
    }
    
    void BigNumbers::printNumber(){
        int x = (int)longNum.size()-1;
        for(int i = x; i > -1; i--){

            std::cout << longNum[i];// << " ";

        }
        std::cout << std::endl;
    }
    
    void BigNumbers::setVector(std::vector<long long int> number){
        longNum = number;
    }
    
    std::vector<long long int>& BigNumbers::getVector(){
        return longNum;
    }
    
    int BigNumbers::compareTo(BigNumbers num){
        int compare = 0;
        
        if(longNum.size() > num.getVector().size()){
            compare = 1;
        }
        else if(longNum.size() < num.getVector().size()){
            compare = -1;
        }
        else{
            bool done = false;
            std::vector<long long int> numbers = num.getVector();
            int i = (int)(longNum.size() - 1);
            while(!done){
                if(longNum[i] > numbers[i]){
                    compare = 1;
                    done = true;
                }//end if
                else if(longNum[i] < numbers[i]){
                    compare = -1;
                    done = true;
                }//end else if
                else{
                    i--;
                }//end else
            }//end while
        }//end else
        return compare;
    }//end compareTO
    
    BigNumbers BigNumbers::operator%(BigNumbers num){
        BigNumbers temp(longNum);
 
        BigNumbers oneValue("1");
        
        
        BigNumbers counter("0");
        bool counting = true;
        
        while(counting){
            counting = false;
            
            if( temp.compareTo(num) >= 0 ){
                
                temp = temp - num;
                counting = true;
                counter = counter + oneValue;
            }
        }
        
        return temp;
    }
    
    BigNumbers BigNumbers::operator/(BigNumbers num){

        
        BigNumbers temp(longNum);
        
        BigNumbers oneValue("1");
        
        BigNumbers counter("0");
        bool counting = true;
        
        while(counting){
            counting = false;
            
            std::cout << temp.compareTo(num) << " - ";
            if( temp.compareTo(num) >= 0 ){
                
                temp = temp - num;
                temp.printNumber();
                counting = true;
                counter = counter + oneValue;
            }
        }
        
        return counter;
    }
    
    
    BigNumbers BigNumbers::operator*(BigNumbers num){
        BigNumbers iterator("0");
        BigNumbers test("0");
        
        if(longNum.size() >= num.getVector().size()){
            BigNumbers temp(num.getVector());
            iterator = temp;
            
            BigNumbers temp2(longNum);
            test = temp2;
            
            num = temp2;
        }
        else{
            BigNumbers temp(longNum);
            iterator = temp;
            
            BigNumbers temp2(num.getVector());
            test = temp2;
            
            num = temp2;
        }
        
        BigNumbers oneValue("1");
        
        std::vector<long long int> iterVector = iterator.getVector();
        
        iterator = iterator - oneValue;
        while( !((iterator.getVector().size() == 1 ) && iterVector[0] == 0) ){
            
            num = num + test;
        
            iterator = iterator - oneValue;
            iterVector = iterator.getVector();
        }
        return num;
    }
    
    BigNumbers BigNumbers::operator+(BigNumbers num){
        
        std::vector<long long int> firstNum;
        std::vector<long long int> secondNum;
        
        if(longNum.size() >= num.getVector().size()){
            firstNum = longNum;
            secondNum = num.getVector();
        }
        else{
            firstNum = num.getVector();
            secondNum = longNum;
        }
        
        long long int temp = 0;
        for(int i = 0; i < firstNum.size(); i++){
            
            if( i < secondNum.size()){
                temp = firstNum[i] + secondNum[i] + temp;
            }
            else{
                temp = firstNum[i] + temp;
            }
            
            if(temp > 9){
                firstNum[i] = temp - 10;
                temp = 1;
            }
            else{
                firstNum[i] = temp;
                temp = 0;
            }
            
        }
        
        if(temp != 0){
            firstNum.push_back(temp);
        }
        
        num.setVector(firstNum);
        return num;

    }
    
    BigNumbers BigNumbers::operator-(BigNumbers num){
       
        std::vector<long long int> emptyVector;
        emptyVector.push_back(0);
        
        std::vector<long long int> firstNum = longNum;
        std::vector<long long int> secondNum = num.getVector();
        
        for(int i = 0; i < firstNum.size(); i++){
            if((i < secondNum.size()) && firstNum[i] >= secondNum[i]){
                firstNum[i] = firstNum[i] - secondNum[i];
                
                if(firstNum[i] == 0 && i == firstNum.size()-1)
                    firstNum = emptyVector;
            }
            else if( i < secondNum.size() && firstNum[i] < secondNum[i]){
                bool digitFound = false;
            
                int x = i + 1;
                int begin = x;
                while(!digitFound && x < firstNum.size()){
                    if(firstNum[x] != 0){
                        digitFound = true;
                        firstNum[x] = firstNum[x] - 1;
                        if(firstNum[x] == 0 && x == firstNum.size()-1)
                            firstNum.pop_back();
                        
                        for(int y = x - 1; y >= begin; y--){
                            firstNum[y] = 9;
                        }
                    }
                    else{
                        x++;
                    }
                }
                
                firstNum[i] = (firstNum[i] + 10) - secondNum[i];
            }
           
            
        }
        num.setVector(firstNum);
        return num;
    }
}
