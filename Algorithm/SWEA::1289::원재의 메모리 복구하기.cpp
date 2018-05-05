//
//  SWEA::1289::원재의 메모리 복구하기.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/4/18.
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

int N, M;

string input;
int restore_count;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    //    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> input;
        vector<int> bit((int)input.size(), 0);
        
        for(int i = 0; i < input.size(); i++) {
            if((input[i] - '0') == 1 && bit[i] == 0) {
                fill(bit.begin() + i, bit.end(), 1);
                restore_count++;
            }
            else if ((input[i] - '0') == 0 && bit[i] == 1){
                fill(bit.begin() + i, bit.end(), 0);
                restore_count++;
            }
        }
        
        cout << "#" << test << " " << restore_count << endl;
        restore_count = 0;
        input.clear();
    }
    return 0;
}

