//
//  SWEA::2814.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/4/18.
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
int N, M;
bool visited[21];
int vertex[21][21];
int maxCount;

void findPath(int start, int count) {
    maxCount = maxCount < count ? count : maxCount;
    
    visited[start] = true;
    for(int i = 1; i <= N; i++) {
        if(vertex[start][i] == 1 && !visited[i]) { // 연결된 간선이 있을 경우
            findPath(i, count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        cin >> N >> M;
        
        int x, y;
        for(int i = 0; i < M; i++) {
            cin >> x >> y;
            vertex[x][y] = 1;
            vertex[y][x] = 1;
        }
        for(int i = 1; i <= N; i++) {
            findPath(i, 1);
            memset(visited, false, sizeof(bool) * 21);
        }
        cout << "#" << test << " " << maxCount << endl;
        memset(visited, false, sizeof(bool) * 21);
        memset(vertex, 0, sizeof(int) * 21 * 21);
        maxCount = 0;
    }
    return 0;
}

