//
//  SWEA::3431::준환이의 운동관리.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/23/18.
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
long long  L, U, X;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> L >> U >> X;
        cout << "#" << test << " ";
        if(X < L)
            cout << L - X << endl;
        else if(L <= X && X <= U)
            cout << 0 << endl;
        else if(X > U)
            cout << -1 << endl;
        
    }
    
    return 0;
}


