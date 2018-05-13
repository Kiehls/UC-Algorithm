//
//  SWEA::1227::미로2.cpp
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

int L = 100;
int map[100][100];
bool visited[100][100];

int start_point_x, start_point_y;
int end_point_x, end_point_y;
bool isFind;
pair<int, int> direction[4] = { {0, 1}, {0 , -1}, {1, 0}, {-1, 0}};

bool isBoundary(int x, int y) {
    return 0 <= x && x < L && 0 <= y && y < L && map[y][x] != 1 && !visited[y][x];
}


void findPath(int x, int y) {
    if(x == end_point_x && y == end_point_y) {
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


int testcase; string tmp;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < L; i++) {
            cin >> tmp;
            for(int j = 0; j < L; j++) {
                map[i][j] = tmp[j] - '0';
                
                if(map[i][j] == 2) {
                    start_point_y = i; start_point_x = j;
                }
                if(map[i][j] == 3) {
                    end_point_y = i; end_point_x = j;
                }
            }
        }
        
        findPath(start_point_x, start_point_y);
        if(isFind) {
            cout << "#" << test << " " << 1 << endl;
        }
        else {
            cout << "#" << test << " " << 0 << endl;
        }
        
        memset(map, 0, sizeof(int) * L * L);
        memset(visited, false, sizeof(bool) * L * L);
        isFind = false;
    }
    return 0;
}

