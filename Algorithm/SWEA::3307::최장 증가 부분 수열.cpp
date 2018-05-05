//
//  SWEA::3307::최장 증가 부분 수열.cpp
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

int N;
vector<unsigned long> arr;


int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        int input; arr.push_back(INT_MIN);
        for(int i = 0; i < N; i++) {
            cin >> input;
            if(arr.back() < input) {
                arr.push_back(input);
            }
            else {
                auto pos = lower_bound(arr.begin(), arr.end(), input);
                *pos = input;
            }
        }
        
        cout << "#" << test << " " << arr.size() << endl;
        arr.clear();
    }
    return 0;
}



