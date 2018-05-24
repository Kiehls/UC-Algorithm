//
//  SWEA::3750::Digit Sum.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/25/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring> //memset
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>

using namespace std;

int N, M, L = 4;

string input;
int sum;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> input;
        for(; input.length() != 1; input = to_string(sum)) {
            sum = 0;
            for(int i = 0; i < input.length(); i++) {
                sum += input[i] - '0';
            }
            if(sum % 10 == 0) sum /= 10;
        }
        printf("#%d %s\n", test, input.c_str());
        
    }
    
    return 0;
}


