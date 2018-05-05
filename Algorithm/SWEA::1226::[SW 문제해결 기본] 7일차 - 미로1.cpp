//
//  SWEA::1226::[SW 문제해결 기본] 7일차 - 미로1.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/24/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>
#include <string.h>

using namespace std;

int N;
int map[16][16];
bool visited[16][16];

int start_x, start_y;
int end_x, end_y;
bool isFind;

pair<int, int> direction[4] = { {0, 1}, {0 , -1}, {1, 0}, {-1, 0}};

bool isBoundary(int x, int y) {
    return 0 <= x && x < 16 && 0 <= y && y < 16 && map[y][x] != 1 && !visited[y][x];
}

void findPath(int x, int y) {
    if(x == end_x && y == end_y) {
        isFind = true;
    }
    for(int i = 0; i < 4; i++) {
        int newx = x + direction[i].first;
        int newy = y + direction[i].second;
        
        if(isBoundary(newx, newy)) {
            visited[newy][newx] = true;
            findPath(newx, newy);
            visited[newy][newx] = false;
        }
    }
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    
    for(int test = 1; test <= 10; test++) {
        cin >> N;
        for(int i = 0; i < 16; i++) {
            string tmp;
            cin >> tmp;
            for(int j = 0; j < 16; j++) {
                map[i][j] = tmp[j] - '0';
                if(map[i][j] == 2) {
                    start_y = i; start_x = j;
                }
                if(map[i][j] == 3) {
                    end_y = i; end_x = j;
                }
            }
        }
        findPath(start_x, start_y);
        if(isFind) {
            cout << "#" << test << " " << 1 << endl;
        }
        else {
            cout << "#" << test << " " << 0 << endl;
        }
        
        memset(map, 0, sizeof(int) * 16 * 16);
        memset(visited, false, sizeof(bool) * 16 * 16);
        isFind = false;
    }
    return 0;
}


