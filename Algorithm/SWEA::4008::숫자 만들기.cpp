//
//  SWEA::4008::숫자 만들기.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/11/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <memory>
#include <limits.h>

using namespace std;

int testcase;
int N;
int _max = INT_MIN, _min = INT_MAX;

int number[12];
int _operator[11];

void findMaxDiff(int index, int value) {
    if(index == N) {
        _max = value > _max ? value : _max;
        _min = value < _min ? value : _min;
        return;
    }
    
    if(_operator[0] > 0) {
        _operator[0]--;
        findMaxDiff(index + 1, value + number[index]);
        _operator[0]++;
    }
    if(_operator[1] > 0) {
        _operator[1]--;
        findMaxDiff(index + 1, value - number[index]);
        _operator[1]++;
    }
    if(_operator[2] > 0) {
        _operator[2]--;
        findMaxDiff(index + 1, value * number[index]);
        _operator[2]++;
    }
    if(_operator[3] > 0) {
        _operator[3]--;
        findMaxDiff(index + 1, value / number[index]);
        _operator[3]++;
    }
}

void clear() {
    _max = INT_MIN; _min = INT_MAX;
    memset(number, 0, sizeof(int) * 12);
    memset(_operator, NULL, sizeof(char) * 11);
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < 4; i++) {
            cin >> _operator[i];
        }
        
        for(int i = 0; i < N; i++)
            cin >> number[i];
        
        findMaxDiff(1, number[0]);
        cout << "#" << test << " " << _max - _min << endl;
        clear();
    }
    return 0;
}

