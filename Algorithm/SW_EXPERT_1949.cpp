//
//  SW_EXPERT_1949.cpp 등산로 조성
//  Algorithm
//
//  Created by Seungsoo on 3/30/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>

int testcase;
int area[8][8];
bool checked[8][8];
int N, K;
int maxHigh;
int maxPath;
int tmpPath = 1;
bool isConstruction;
std::pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
std::vector<std::pair<int, int>> maxPoint;

bool isBoundary(int x, int y) {
    return (0 <= x && x <= N) && (0 <= y && y <= N) && !checked[x][y] && area[x][y] != 0;
}

bool isPossible(int nxtValue, int curValue) {
    if(nxtValue < curValue)
        return true;
    
    return false;
}

void findPath(int x, int y, int curValue, int count) {
    maxPath = maxPath > count ? maxPath : count;
    checked[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int X = x + direction[i].first;
        int Y = y + direction[i].second;
        
        if(isBoundary(X, Y)) {
            if(isPossible(area[X][Y], curValue)) { // K만큼 깍지 않아도 되는 경우
                findPath(X, Y, area[X][Y], count + 1);
                checked[X][Y] = false;
            }
            else { // 등산로를 깍아야하는 경우 /** 문제 파트
                if(!isConstruction) { // 공사를 진행하지 않은 경우
                    for(int depth = 1; depth <= K; depth++) {
                        if(isPossible(area[X][Y] - depth, curValue)) {
                            isConstruction = true;
                            area[X][Y] -= depth;
                            findPath(X, Y, area[X][Y], count + 1);
                            area[X][Y] += depth; checked[X][Y] = false;
                        }
                    }
                    isConstruction = false;
                }
            }
        }
    }
}

void findMaxPath() { // 제일 높은 지점에서부터의 traversal 시작
    for(int i = 0; i < maxPoint.size(); i++) {
        int x = maxPoint[i].first;
        int y = maxPoint[i].second;
        
        findPath(x, y, area[x][y], 1);
        checked[x][y] = false;
    }
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> N >> K;
        
        for(int i = 0; i < N; i++) { // 등산로 정보 instream
            for(int j = 0; j < N; j++) {
                std::cin >> area[i][j];
                maxHigh = maxHigh < area[i][j] ? area[i][j] : maxHigh;
            }
        }
        for(int i = 0 ; i < N; i++) { // 최고 높이의 봉우리 Point 찾기
            for(int j = 0; j < N; j++) {
                if(maxHigh == area[i][j]) {
                    maxPoint.push_back({i, j});
                }
            }
        }
        
        findMaxPath();
        
        std::cout << "#" << test << " " << maxPath << std::endl;
        memset(area, 0, sizeof(int) * 8 * 8);
        memset(checked, false, sizeof(int) * 8 * 8);
        maxPath = 0;
    }
    return 0;
}

