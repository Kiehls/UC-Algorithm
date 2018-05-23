//
//  SWEA::4050::재관이의 대량 할인.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/23/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>

using namespace std;

int N, M, L = 4;

vector<int> clothe;
int pairing, rest;

int findMaximumSale() {
    int sum = 0;
    sort(clothe.rbegin(), clothe.rend());
    
    vector<int> tmp; int index = 0;
    for(int i = 0; i < pairing; i++) {
        for(int j = 0; j < 2; j++) {
            //            tmp.push_back(clothe[index++]);
            sum += clothe[index++];
        }
        index++;
    }
    for(int i = 0; i < rest; i++) {
        sum += clothe[index++];
    }
    
    return sum;
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N; int tmp;
        for(int i = 0; i < N; i++) {
            cin >> tmp; clothe.push_back(tmp);
        }
        pairing = N / 3; rest = N % 3;
        cout << "#" << test << " " << findMaximumSale() << endl;
        clothe.clear();
    }
    return 0;
}

