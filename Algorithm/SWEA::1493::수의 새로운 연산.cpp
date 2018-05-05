//
//  SWEA::1493::수의 새로운 연산.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/2/18.
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
#include <functional>

using namespace std;

int p, q;

pair<int, int> getPos(int value) {
    
    
    return {0, 0};
}

int getValue(int x, int y) {
    return 0;
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    //    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> p >> q;
        
        auto _first = getPos(p );
        auto _second = getPos(q);
        
        auto value = getValue(_first.first + _second.first, _first.second + _second.second);
        cout << "#" << test << " " << value << endl;
        
    }
    return 0;
}



