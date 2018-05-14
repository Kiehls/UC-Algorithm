//
//  SWEA::1219::길찾기.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/14/18.
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

int v1, v2;
int pathLength;
bool isPossible;
bool visited[100];
vector<int> vertex[100];


void findPath(int start) {
    for(int i = 0; i < vertex[start].size(); i++) {
        if(vertex[start][i] == 99)
            isPossible = true;
    }
    
    for(int i = 0; i < vertex[start].size(); i++) {
        visited[start] = true;
        findPath(vertex[start][i]);
        visited[start] = false;
    }
}

int testcase; string tmp;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N >> pathLength;
        for(int i = 0; i < pathLength; i++) {
            cin >> v1 >> v2;
            vertex[v1].push_back(v2);
        }
        findPath(0);
        if(isPossible) {
            cout << "#" << test << " " << 1 << endl;
        }
        else
            cout << "#" << test << " " << 0 << endl;
        
        memset(vertex, 0, sizeof(vector<int>) * 100);
        memset(visited, false, sizeof(bool) * 100);
        isPossible = false;
    }
    return 0;
}

