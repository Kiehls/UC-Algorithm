//
//  acmicpc::11403::경로 찾기.cpp
//  Algorithm
//
//  Created by Seungsoo on 6/5/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring> //memset
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>

using namespace std;

int N;
int map[101][101];
int copied_map[101][101];
bool visited[101];

void findPath(int row, int col) {
    
    visited[col] = true;
    copied_map[row][col] = 1;
    
    for(int i = 0; i < N; i++) {
        if(map[col][i] && !visited[i]) {
            findPath(row, i);
        }
    }
}

void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << copied_map[i][j] << " ";
        }
        cout << endl;
    }
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j]; copied_map[i][j] = map[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j]) {
                findPath(i, j);
                memset(visited, false, sizeof(bool) * 101);
            }
        }
    }
    print();
}



