//
//  SWEA::3376::파도반 수열.cpp
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

long long numbers[100] = { 1, 1, 1, 2, 2};
int N;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int i = 5; i < 100; i++) {
        numbers[i] = numbers[i - 1] + numbers[i - 5];
    }
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        cout << "#" << test << " " << numbers[N - 1] << endl;
    }
    return 0;
}


