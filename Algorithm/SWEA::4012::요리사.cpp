//
//  SWEA::4012::요리사.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/10/18.
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

using namespace std;

int testcase;
int map[17][17];
int N;
int minDiff = 99999;
bool menuVariety[17];


int getFoodValueA() {
    auto foodValue = 0;
    for(int i = 1; i <= N; i++) {
        if(menuVariety[i]) {
            for(int j = 1; j <= N; j++) {
                if(menuVariety[j]) {
                    foodValue += map[i][j];
                }
            }
        }
    }
    return foodValue;
}

int getFoodValueB() {
    auto foodValue = 0;
    for(int i = 1; i <= N; i++) {
        if(!menuVariety[i]) {
            for(int j = 1; j <= N; j++) {
                if(!menuVariety[j]) {
                    foodValue += map[i][j];
                }
            }
        }
    }
    return foodValue;
}
void findMininumDiff(int menu, int menuCount) {
    if(menuCount == N / 2) {
        int foodValueA = getFoodValueA();
        int foodValueB = getFoodValueB();
        
        minDiff = minDiff > abs(foodValueA - foodValueB) ? abs(foodValueA - foodValueB) : minDiff;
        return;
    }
    
    for(int i = menu; i <= N; i++) {
        menuVariety[i] = true;
        findMininumDiff(i + 1, menuCount + 1);
        menuVariety[i] = false;
    }
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> map[i][j];
            }
        }
        
        findMininumDiff(1, 0);
        cout << "#" << test << " " << minDiff << endl;
        
        memset(map, 0, sizeof(int) * 16 * 16);
        memset(menuVariety, false, sizeof(bool) * 17);
        minDiff = 99999;
    }
    return 0;
}

