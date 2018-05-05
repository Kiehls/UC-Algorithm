//
//  SWEA::3408::세가지 합 구하기.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/25/18.
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

unsigned long long N;
unsigned long long S1, S2, S3;


int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        
        S1 = N * (N + 1) / 2;
        S2 = N * N;
        S3 = N * (N + 1);
        
        cout << "#" << test << " " << S1 << " " << S2 << " " << S3 << endl;
    }
    return 0;
}


