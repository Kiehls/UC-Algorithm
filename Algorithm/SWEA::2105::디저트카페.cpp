//
//  SWEA::2105::디저트카페.cpp
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
#define FAIL -1

using namespace std;

int testcase;
int N;
int start_x, start_y;
int maxMenu = -1;

int map[20][20];
bool dessertMenu[101];

pair<int, int> direction[4] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}}; // 우하, 좌하, 좌상, 우상 --> 반시계 방향

bool isBoundary(int x, int y) { // 경계를 나눠서 접근..?
    return 0 <= x && x < N && 0 <= y && y < N;
}

void findMaxDessert(int x, int y, int way, int count) {
    if(start_x == x && start_y == y && way == 3) {
        maxMenu = count > maxMenu ? count : maxMenu;
    }
    
    if(dessertMenu[map[x][y]]) // 방문 경험이 있는지
        return;
    dessertMenu[map[x][y]] = true;
    
    
    int new_x = x + direction[way].first;
    int new_y = y + direction[way].second;
    
    if(isBoundary(new_x, new_y)) {
        findMaxDessert(new_x, new_y, way, count + 1);
        findMaxDessert(new_x, new_y, way + 1, count + 1);
    }
    dessertMenu[map[x][y]] = false;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                start_x = i; start_y = j;
                findMaxDessert(i, j, 0, 0);
            }
        }
        if(maxMenu < 4) {
            cout << "#" << test << " " << FAIL << endl;
        }
        else {
            cout << "#" << test << " " << maxMenu << endl;
        }
        memset(map, 0, sizeof(int) * 21 * 21);
        memset(dessertMenu, false, sizeof(bool) * 101);
        maxMenu = -1;
    }
    return 0;
}
