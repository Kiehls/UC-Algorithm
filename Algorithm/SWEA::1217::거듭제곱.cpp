//
//  SWEA::1217::거듭제곱.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/26/18.
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
#include <functional>

using namespace std;

int N, M;
int POW(int start, int exp) {
    if(M == 0)
        return 1;
    
    if(exp == M - 1)
        return start;
    
    return POW(start * N, exp + 1);
}
int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //cin >> testcase;
    
    for(int test = 1; test <= 10; test++) {
        cin >> testcase >> N >> M;
        
        int tmp = POW(N, 0);
        
        
        cout << "#" << test << " " << tmp << endl;
    }
    return 0;
}




