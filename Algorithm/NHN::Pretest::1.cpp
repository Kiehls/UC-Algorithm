//
//  NHN::Pretest::1.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/17/18.
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

using namespace std;
int testcase;

int num;
vector<string> nums;
bool finished;

int main() {
    cin >> num;
    
    int origin = num;
    int ans = 0;
    
    for(int i = 0; i < 3; i++) {
        string tmp = to_string(origin);
        reverse(tmp.begin(), tmp.end());
        int reversed = stoi(tmp);
        
        int sum = origin + reversed;
        string reversing = to_string(sum);
        reverse(reversing.begin(), reversing.end());
        int reversed_sum = stoi(reversing);
        
        if(sum == reversed_sum) {
            ans = sum;
            finished = true;
            break;
        }
        origin = sum;
    }
    
    if(finished) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}

