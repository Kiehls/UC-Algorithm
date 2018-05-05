//
//  SWEA::3809::화섭이의 정수 나열.cpp
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

int N;
string numbers = "";
int ans = 0;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            int num;
            cin >> num;
            numbers += to_string(num);;
        }
        while(true) {
            string tmp = to_string(ans);
            if(numbers.find(tmp) != string::npos) {
                ans++;
            }
            else
                break;
        }
        cout << "#" << test << " " << ans << endl;
        ans = 0;
        numbers.clear();
    }
    
    return 0;
}


