//
//  acmicpc::1012::유기농 배추.cpp
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

int N, M, K;
int minBug;
int map[51][51];
bool visited[51][51];
pair<int, int> direction[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isBoundary(int x, int y) {
    return 0 <= x && x <= N && 0 <= y && y <= M;
}

void findMinBug(int x, int y) {
    visited[x][y] = true;
    
    for(int i = 0; i < 4; i++) {
        int newx = x + direction[i].first;
        int newy = y + direction[i].second;
        
        if(isBoundary(newx, newy) && map[newx][newy] && !visited[newx][newy]) {
            findMinBug(newx, newy);
        }
    }
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    for(int test = 0; test < testcase; test++) {
        cin >> M >> N >> K;
        int x, y;
        for(int i = 0; i < K; i++) {
            cin >> x >> y; map[y][x] = 1;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] && !visited[i][j]) {
                    findMinBug(i, j); minBug++;
                }
            }
        }
        cout << minBug << endl;
        memset(map, 0, sizeof(int) * 50 * 50);
        memset(visited, false, sizeof(bool) * 50 * 50);
        minBug = 0;
    }
    
}


