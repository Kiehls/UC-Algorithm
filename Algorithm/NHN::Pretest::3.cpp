//
//  NHN::Pretest::3.cpp
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

long long _min = LONG_LONG_MAX;
long long _max = LONG_LONG_MIN;

vector<int> tokenizingString(string input) {
    vector<int> numbers;
    stringstream stream(input);
    string num;
    
    while(getline(stream, num, ' ')) {
        numbers.push_back(stoi(num));
    }
    
    return numbers;
}

int main() {
    string inputString;
    getline(cin, inputString);
    
    auto numbers = tokenizingString(inputString);
    
    do {
        string tmp = "";
        for(int i = 0; i < numbers.size(); i++) {
            tmp += to_string(numbers[i]);
        }
        auto num = stoll(tmp);
        _min = _min > num ? num : _min;
        _max = _max < num ? num : _max;
        
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    cout << _min + _max << endl;
    
    return 0;
}

