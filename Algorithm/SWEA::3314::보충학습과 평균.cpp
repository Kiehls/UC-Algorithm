//
//  SWEA::3314::보충학습과 평균.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/24/18.
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

using namespace std;

int ans;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        int tmp;
        for(int i = 0; i < 5; i++) {
            cin >> tmp;
            if(tmp < 40)
                ans += 40;
            else
                ans += tmp;
        }
        printf("#%d %d\n", test, ans / 5);
        ans = 0;
    }
    
    return 0;
}


