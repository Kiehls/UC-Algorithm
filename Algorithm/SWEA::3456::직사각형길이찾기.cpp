//
//  SWEA::3456::직사각형길이찾기.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/4/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <memory>
#define FAIL -1

using namespace std;

int testcase;
int side[101];

int findSide() {
    for(int i = 1; i < 101; i++) {
        if(side[i] == 1 || side[i] == 3)
            return i;
    }
    return 0;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        auto tmp = 0;
        for(int i = 0; i < 3; i++) {
            cin >> tmp;
            side[tmp]++;
        }
        cout << "#" << test << " " << findSide() << endl;;
        memset(side, 0, sizeof(int) * 101);
    }
    return 0;
}


