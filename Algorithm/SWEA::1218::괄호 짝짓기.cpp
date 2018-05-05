//
//  SWEA::1218::괄호 짝짓기.cpp
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
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>
#include <string.h>
#include <functional>

using namespace std;

int N, M;

char in[4] = { '}', ']', '>', ')'};
char out[4] = { '{', '[', '<', '('};

char matching(char input) {
    for(int i = 0; i < 4; i++) {
        if(input == in[i])
            return out[i];
    }
    return NULL;
}

bool isMatch = true;
int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N; char tmp; stack<char> palindrome;
        for(int i = 0; i < N; i++) {
            cin >> tmp;
            if(tmp == '{' || tmp == '[' || tmp == '<' || tmp == '(') {
                palindrome.push(tmp);
            }
            else {
                auto identifier = palindrome.top();
                if(identifier == matching(tmp)) {
                    palindrome.pop();
                }
                else {
                    isMatch = false;
                }
            }
        }
        
        if(!isMatch || !palindrome.empty()) {
            cout << "#" << test << " " << 0 << endl;
        }
        else
            cout << "#" << test << " " << 1 << endl;
        isMatch = true;
    }
    return 0;
}
