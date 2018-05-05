//
//  SWEA::1228::암호문1.cpp
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
#include <list>
#include <functional>

using namespace std;

int N, M;

vector<int> origin;
int operation;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            origin.push_back(tmp);
        }
        
        cin >> operation; char tmp; int index, count, value;
        for(int i = 0; i < operation; i++) {
            cin >> tmp >> index >> count;
            for(int j = 0; j < count; j++) {
                cin >> value;
                origin.insert(origin.begin() + index + j, value);
            }
        }
        cout << "#" << test << " ";
        for(int i = 0; i < 10; i++)
            cout << origin[i] << " ";
        cout << endl;
        
        origin.clear();
    }
    return 0;
}




