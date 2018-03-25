//
//  BEAKJOON10156(과자).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/13/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
int main(int argc, const char * argv[]) {
    auto price = 0, cookie = 0, money = 0;
    std::cin >> price >> cookie >> money;
    
    if((money - price * cookie) < 0) {
        std::cout << (price * cookie) - money <<std::endl;
    }
    else {
        std::cout << 0 << std::endl;
    }
    
    return 0;
}
