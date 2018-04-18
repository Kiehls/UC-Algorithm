//
//  SWEA::4014::활주로 건설.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/14/18.
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

#define UP 1
#define DOWN 0

using namespace std;

int testcase;
int N, X;

int map[20][20];
bool installed[20];
int possibleLandingStrip = 0;

bool isPossibleCol(int depth, int index, int dir) {
    int level = map[depth][index];
    if(dir == UP) { // 방향이 오르막인 경우 --> 현재 위치로부터 X만큼 뒤의 위치 레벨이 같아야 함
        if(index - X + 1 < 0)
            return false;
        
        for(int i = 0; i < X; i++) {
            if(installed[index - i])
                return false;
            
            if(map[depth][index - i] != level) {
                return false;
            }
            installed[index - i] = true;
        }
        return true;
    }
    else { // 방향이 내리막인 경우 --> 현재 위치로부터 X만큼 앞의 위치 레벨이 같아야 함
        if(index + X >= N)
            return false;
        
        for(int i = 1; i <= X; i++) {
            installed[index + i] = true;
            if(map[depth][index + i] - 1 != level) {
                return false;
            }
        }
        return true;
    }
}

bool findLandingStripCol(int curHeight, int idx) { // 가로열 탐색
    if(idx == N - 1)
        return true;
    if(map[curHeight][idx] == map[curHeight][idx + 1]) { // 평지
        return findLandingStripCol(curHeight, idx + 1);
    }
    else if(map[curHeight][idx] + 1 == map[curHeight][idx + 1]) {// 오르막
        //        if(isPossibleCol(curHeight, idx, UP)) {
        if(idx - X + 1 < 0)
            return false;
        for(int i = 0; i < X; i++) {
            if(installed[idx - i])
                return false;
            if(map[curHeight][idx - i] != map[curHeight][idx])
                return false;
            installed[idx - i] = true;
        }
        return findLandingStripCol(curHeight, idx + 1);
        //        }
    }
    else if(map[curHeight][idx] - 1 == map[curHeight][idx + 1]) { // 내리막
        //        if(isPossibleCol(curHeight, idx, DOWN)) {
        if(idx + X >= N)
            return false;
        for(int i = 1; i <= X; i++) {
            installed[idx + i] = true;
            if(map[curHeight][idx + i] + 1 != map[curHeight][idx])
                return false;
        }
        return findLandingStripCol(curHeight, idx + X);
        //        }
    }
    return false;
}

bool isPossibleRow(int width, int index, int up) {
    int level = map[index][width];
    if(up) { // 방향이 오르막인 경우 --> 현재 위치로부터 X만큼 뒤의 위치 레벨이 같아야 함
        if(index - X + 1 < 0)
            return false;
        
        for(int i = 0; i < X; i++) {
            if(installed[index - i])
                return false;
            
            if(map[index - i][width] != level) {
                return false;
            }
            installed[index - i] = true;
        }
        return true;
    }
    else { // 방향이 내리막인 경우 --> 현재 위치로부터 X만큼 앞의 위치 레벨이 같아야 함
        if(index + X >= N)
            return false;
        
        for(int i = 1; i <= X; i++) {
            installed[index + i] = true;
            if(map[index + i][width] - 1 != level) {
                return false;
            }
        }
        return true;
    }
}

bool findLandingStripRow(int idx, int curWidth) { // 세로열 탐색
    if(idx == N - 1)
        return true;
    if(map[idx][curWidth] == map[idx + 1][curWidth])
        return findLandingStripRow(idx + 1, curWidth);
    
    else if(map[idx][curWidth] + 1 == map[idx + 1][curWidth]) {
        //        if(isPossibleRow(curWidth, idx, 1)) {
        if(idx - X + 1 < 0)
            return false;
        for(int i = 0; i < X; i++) {
            if(installed[idx - i])
                return false;
            if(map[idx - i][curWidth] != map[idx][curWidth])
                return false;
            installed[idx - i] = true;
        }
        return findLandingStripRow(idx + 1, curWidth);
        //        }
    }
    
    else if(map[idx][curWidth] - 1 == map[idx + 1][curWidth]) {
        //        if(isPossibleRow(curWidth, idx, 0)) {
        if(idx + X >= N)
            return false;
        for(int i = 1; i <= X; i++) {
            installed[idx + i] = true;
            if(map[idx + i][curWidth] + 1 != map[idx][curWidth])
                return false;
        }
        return findLandingStripRow(idx + X, curWidth);
        //        }
    }
    return false;
}

void clear() {
    possibleLandingStrip = 0;
    memset(map, 0, sizeof(int) * 20 * 20);
    memset(installed, false, sizeof(bool) * 20);
}

int main() {
    std::cin >> testcase;
    for (int test = 1; test <= testcase; test++) {
        cin >> N >> X;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        
        for(int i = 0; i < N; i++) {
            possibleLandingStrip = findLandingStripCol(i, 0) ? possibleLandingStrip + 1 : possibleLandingStrip;
            memset(installed, false, sizeof(bool) * 20);
        }
        
        for(int i = 0; i < N; i++) {
            possibleLandingStrip = findLandingStripRow(0, i) ? possibleLandingStrip + 1 : possibleLandingStrip;
            memset(installed, false, sizeof(bool) * 20);
        }
        
        cout << "#" << test << " " << possibleLandingStrip << endl;
        clear();
    }
    return 0;
}


