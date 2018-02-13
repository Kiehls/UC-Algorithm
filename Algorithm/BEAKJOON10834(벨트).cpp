//
//  BEAKJOON10834(벨트).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/1/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>

int data[3][1000];
int main(int argc, const char * argv[]) {
    int num_of_belt = 0, direction = 0;
    std::cin >> num_of_belt;
    
    for(int i = 0; i < num_of_belt; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> data[j][i];
        }
    }
    int numerator = 1;
    for(int i = 0 ; i < num_of_belt; i++) {
        numerator = numerator * data[1][i] / data[0][i];
    }
    for(int i = 0; i < num_of_belt; i++)
        direction += data[2][i];
    
    std::cout << direction % 2 << " " << numerator << std::endl;
    
    return 0;
}
