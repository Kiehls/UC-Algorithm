//
//  SWEA::3975::승률 비교하기.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/20/18.
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
#include <map>

using namespace std;
                            // C++ cout보다 printf가 속도면에서 빠름.
int A, B, C, D;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> A >> B >> C >> D;
        
        if(A * D > B * C)
            printf("#%d ALICE\n", test);
        //            cout << "#" << test << " ALICE" << endl;
        else if(A * D < B * C)
            printf("#%d BOB\n", test);
        //            cout << "#" << test << " BOB" << endl;
        else if(A * D == B * C)
            printf("#%d DRAW\n", test);
        //            cout << "#" << test << " DRAW" << endl;
    }
    
    return 0;
}


