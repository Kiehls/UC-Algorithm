//
//  SWEA::1213::String.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/27/18.
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
string inputString;
string searchString;
int findstring;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        cin >> inputString; //getline(cin, searchString);
        cin >> searchString;
        
        for(int i = 0; i < searchString.length(); i++) {
            auto tmp = searchString.substr(i, inputString.size());
            if(inputString == tmp) {
                findstring++;
            }
        }
        
        cout << "#" << test << " " << findstring << endl;
        findstring = 0;
    }
    return 0;
}



