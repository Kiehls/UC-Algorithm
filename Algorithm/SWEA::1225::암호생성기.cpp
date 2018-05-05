//
//  SWEA::1225::암호생성기.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/27/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>
#include <string.h>
#include <functional>

using namespace std;

int N, M;

deque<int> nums;

bool isZero() {
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] <= 0) {
            nums[i] = 0;
            return true;
        }
    return false;
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //cin >> testcase;
    
    for(int test = 1; test <= 10; test++) {
        cin >> N;
        int num;
        for(int i = 0; i < 8; i++) {
            cin >> num;
            nums.push_back(num);
        }
        int minus = 1;
        while(!isZero()) {
            auto _front = nums.front();
            nums.pop_front();
            nums.push_back(_front - minus++);
            if(minus > 5)
                minus = 1;
        }
        
        cout << "#" << test << " ";
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        
        nums.clear();
    }
    return 0;
}



