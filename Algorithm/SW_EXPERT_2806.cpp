//
//  SW_EXPERT_2806.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/28/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>

int testcase;
int N;
int numcase;

bool row[11];
bool rightside[121];
bool leftside[121];


void Nqueen(int count) {
    if(count == N) {
        numcase++;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(row[i] == 1)
            continue;
        if(rightside[count + i] == 1)
            continue;
        if(leftside[N - 1 - (count - i)] == 1)
            continue;
        
        row[i] = 1;
        rightside[count + i] = 1;
        leftside[N - 1 - (count - i)] = 1;
        
        Nqueen(count + 1);
        
        row[i] = 0;
        rightside[count + i] = 0;
        leftside[N - 1 - (count - i)] = 0;
    }
    
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> N; Nqueen(0);
        std::cout << "#" << test << " " << numcase << std::endl;
        numcase = 0;
        memset(row, 0, sizeof(int) * 10);
        memset(leftside, 0, sizeof(int) * 10);
        memset(rightside, 0, sizeof(int) * 10);
    }
    return 0;
}


