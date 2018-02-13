//
//  BEAKJOON10162(전자레인지).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/6/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>

int timeA = 300, timeB = 60, timeC = 10;
int main(int argc, const char * argv[]) {
    int countA, countB, countC, timer = 0;
    std::cin >> timer;
    
    countA = timer / timeA;
    timer %= timeA;
    
    countB = timer / timeB;
    timer %= timeB;
    
    countC = timer / timeC;
    timer %= timeC;
    
    if(timer == 0) {
        std::cout << countA << " " << countB << " " << countC << std::endl;
    }
    else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}

