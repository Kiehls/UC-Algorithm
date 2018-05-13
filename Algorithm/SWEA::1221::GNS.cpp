//
//  SWEA::1221::GNS.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/8/18.
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

vector<int> ans;

vector<string> numeric = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int strToint(string input) {
    if(input == "ZRO")
        return 0;
    else if(input == "ONE")
        return 1;
    else if(input == "TWO")
        return 2;
    else if(input == "THR")
        return 3;
    else if(input == "FOR")
        return 4;
    else if(input == "FIV")
        return 5;
    else if(input == "SIX")
        return 6;
    else if(input == "SVN")
        return 7;
    else if(input == "EGT")
        return 8;
    else
        return 9;
}


int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    //    testcase = 10;
    
    string tmp;
    for(int test = 1; test <= testcase; test++) {
        cin >> tmp >> N;
        for(int i = 0; i < N; i++) {
            cin >> tmp;
            ans.push_back(strToint(tmp));
        }
        
        sort(ans.begin(), ans.end());
        cout << "#" << test << " ";
        for(int i = 0; i < ans.size(); i++) {
            cout << numeric[ans[i]] << " ";
        }
        cout << endl;
        ans.clear();
    }
    
    return 0;
}

