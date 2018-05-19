//
//  SWEA::1222::계산기1.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/19/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>
#include <string.h>
#include <list>
#include <functional>

using namespace std;

int N, M, L;

string formula;
int calculate(int a, int b) {
    return a + b;
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N; cin >> formula; int sum = 0;
        for(int i = 0; i < formula.length(); i += 2) {
            sum += formula[i] - '0';
        }
        cout << "#" << test << " " << sum << endl;
    }
    return 0;
}


