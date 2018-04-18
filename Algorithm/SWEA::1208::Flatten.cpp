//
//  SWEA::1208::Flatten.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/5/18.
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

using namespace std;

int testcase;
vector<int>map;
int dump;

int gap;

int findMin() {
    int min = 999999, idx = 0;
    for(int i = 0; i < map.size(); i++) {
        if(min > map[i]) {
            min = map[i];
            idx = i;
        }
    }
    return idx;
}
int findMax() {
    int max = 0, idx = 0;
    for(int i = 0; i < map.size(); i++) {
        if(max < map[i]) {
            max = map[i];
            idx = i;
        }
    }
    return idx;
}
void find() {
    for(int i = 0; i < dump; i++) {
        int maxIdx = findMax();
        int minIdx = findMin();
        if(maxIdx == minIdx)
            return;
        
        map[maxIdx]--;
        map[minIdx]++;
    }
    int max_index = findMax();
    int min_index = findMin();
    
    gap = map[max_index] - map[min_index];
}

int main() {
    //std::cin >> testcase;
    for(int test = 1; test <= 10; test++) {
        cin >> dump;
        for(int i = 0; i < 100; i++) {
            auto tmp = 0;
            cin >> tmp;
            map.push_back(tmp);
        }
        find();
        cout << "#" << test << " " << gap << endl;
        gap = 0;
        map.clear();
    }
    return 0;
}

