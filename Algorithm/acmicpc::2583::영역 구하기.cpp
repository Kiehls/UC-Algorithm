//
//  acmicpc::2583::영역 구하기.cpp
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

int M, N, K;
int area;
vector<int> ans;
int map[101][101];
bool visited[101][101];


void print() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
bool isBoundary(int row, int col) {
    return 0 <= row && row < M && 0 <= col && col < N;
}
void findSpace(int row, int col) {
    if(!isBoundary(row, col))
        return;
    if(visited[row][col])
        return;
    if(map[row][col])
        return;
    
    area++;
    visited[row][col] = true;
    
    findSpace(row + 1, col);
    findSpace(row - 1, col);
    findSpace(row, col + 1);
    findSpace(row, col - 1);
    
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> M >> N >> K;
    int x1, y1, x2, y2;
    for(int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++) {
                map[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(!map[i][j] && !visited[i][j]) {
                findSpace(i, j); ans.push_back(area); area = 0;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    ans.clear();
    memset(map, 0, sizeof(int) * 101 * 101);
    memset(visited, false, sizeof(bool) * 101 * 101);
}
