//
//  BEAKJOON10833(사과).cpp
//  Algorithm
//
//  Created by Seungsoo on 1/25/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int num_of_school = 0, left = 0;
    int students = 0, apple = 0;
    std::cin >> num_of_school;
    
    for(int i = 0; i < num_of_school; i++) {
        std::cin >> students >> apple;
        left += apple % students;
    }
    std::cout << left << std::endl;
    
    return 0;
}
