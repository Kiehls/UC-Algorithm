//
//  SW_EXPERT_1952.cpp 수영장
//  Algorithm
//
//  Created by Seungsoo on 4/2/18.
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

enum {DAY, MONTH, TMONTH, YEAR};

int pay[4];
int schedule[13];
int minPay = 999999;

void findMinPay(int month, int cost) {
    if(month > 12) {
        minPay = minPay < cost ? minPay : cost;
        return;
    }
    
    findMinPay(month + 1, schedule[month] * pay[0] + cost);
    findMinPay(month + 1, cost + pay[1]);
    findMinPay(month + 3, cost + pay[2]);
    findMinPay(month + 12, cost + pay[3]);
    
}
int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        for(int i = 0; i < 4; i++)
            cin >> pay[i];
        for(int i = 1; i <= 12; i++)
            cin >> schedule[i];
        
        findMinPay(0, 0);
        
        std::cout << "#" << test << " " << minPay << std::endl;
        minPay = 99999;
        memset(pay, 0, sizeof(int) * 4);
        memset(schedule, 0, sizeof(int) * 13);
    }
    return 0;
}


