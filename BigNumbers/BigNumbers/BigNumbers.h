//
//  BigNumbers.h
//  BigNumbers
//
//  Created by Matthew Villasenor on 5/13/19.
//  Copyright © 2019 Matthew Villasenor. All rights reserved.
//

#ifndef BigNumbers_h
#define BigNumbers_h

#include <stdexcept>
#include <vector>

namespace BigNums{
    
    
    class BigNumbers{
    
        std::vector<long long int> longNum;
        
        std::vector<long long int>& getVector();
        
        BigNumbers(std::vector<long long int> number);
        
        void setVector(std::vector<long long int> number);
        
    public:
        //static std::vector<long long int> longNum;
        
        BigNumbers(std::string bignum);
        
        void printNumber();
        
        BigNumbers operator-(BigNumbers num);
        
        BigNumbers operator+(BigNumbers num);
        
        BigNumbers operator*(BigNumbers num);
        
        BigNumbers operator/(BigNumbers num);
        
        BigNumbers operator%(BigNumbers num);
        
    };
    
}

#endif /* BigNumbers_h */
