//
//  SWEA::1234::비밀번호.cpp
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

string password;
deque<char> input;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N >> password;
        
        for(int i = 0; i < password.size(); i++) {
            if(!input.empty()) {
                if(input.back() != password[i]) {
                    input.push_back(password[i]);
                }
                else
                    input.pop_back();
            }
            else
                input.push_back(password[i]);
            
        }
        cout << "#" << test << " ";
        for(int i = 0; i < input.size(); i++)
            cout << input[i];
        cout << endl;
        input.clear();
    }
    
    return 0;
}

