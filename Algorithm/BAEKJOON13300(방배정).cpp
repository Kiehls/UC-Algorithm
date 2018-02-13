//
//  BAEKJOON13300(방배정).cpp
//  Algorithm
//
//  Created by Seungsoo on 1/15/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <cstring>
#define GRADE 7

enum {GIRL, BOY};

int main(int argc, const char * argv[]) {
    // insert code here...
    int num_of_total_student = 0, num_of_max_student = 0;
    std::cin >> num_of_total_student >> num_of_max_student;
    
    int num_of_room = 0, gender, grade;
    int students[2][GRADE];
    memset(students, 0, sizeof(int) * 2 * GRADE);
    
    for(int i = 0; i < num_of_total_student; i++) {
        std::cin >> gender >> grade;
        students[gender][grade] += 1;
    }
    
    for(int i = 0; i < GRADE; i++) {
        num_of_room += students[GIRL][i] / num_of_max_student + students[BOY][i] / num_of_max_student;
        if(students[GIRL][i] % num_of_max_student != 0) {
            num_of_room++;
        }
        if(students[BOY][i] % num_of_max_student != 0) {
            num_of_room++;
        }
    }
    std::cout << num_of_room << std::endl;
    
    return 0;
}

