//
//  BEAKJOON14697(방배정하기).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/2/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
int roomA, roomB, roomC, students;
int a, b, c;
int main(int argc, const char * argv[]) {
    std::cin >> roomA >> roomB >> roomC >> students;
    
    for(int i = 0; i <= students; i++) {
        a = roomA * i;
        for(int j = 0; j <= students; j++) {
            b = roomB * j;
            for(int k = 0; k <= students; k++) {
                c = roomC * k;
                if(a + b + c == students) {
                    std::cout << 1 << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}

