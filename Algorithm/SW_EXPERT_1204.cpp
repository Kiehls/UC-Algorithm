//
//  SW_EXPERT_1204.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/26/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>

int score[101];
int testcase;
auto tmp = 0;
auto max = 0;
auto num = 0;

int main() {
    for(int test = 1; test <= 10; test++) {
        std::cin >> testcase;
        for(int i = 0; i < 1000; i++) {
            std::cin >> tmp;
            score[tmp]++;
        }
        
        for(int i = 0; i <= 100; i++) {
            if(max <= score[i]) {
                max = score[i];
                num = i;
            }
        }
        
        std::cout << "#" << testcase << " " << num << std::endl;
        memset(score, 0, sizeof(int) * 101);
        max = num = 0;
    }
    return 0;
}
