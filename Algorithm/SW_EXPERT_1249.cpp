//
//  SW_EXPERT_1249.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/1/18.
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

int testcase;
int N;

std::queue<std::pair<int, int>> paths;
int map[101][101];
int memorize[101][101];

std::pair<int, int> direction[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; //상 좌 하 우

bool isBoundary(int x, int y) {
    return (0 <= x && x < N) && (0 <= y && y < N);
}

void findminRestore(int x, int y, int restore) {
    paths.push({x, y});
    
    while(!paths.empty()) {
        int cur_x = paths.front().first;
        int cur_y = paths.front().second;
        paths.pop();
        
        for(int i = 0; i < 4; i++) {
            int new_x = cur_x + direction[i].first;
            int new_y = cur_y + direction[i].second;
            
            if(isBoundary(new_x, new_y)) {
                if(memorize[new_x][new_y] > memorize[cur_x][cur_y] + map[new_x][new_y]) {
                    memorize[new_x][new_y] = memorize[cur_x][cur_y] + map[new_x][new_y];
                    paths.push({new_x, new_y});
                }
            }
        }
    }
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> N;
        char tmp[100][100] = {NULL, };
        for(int i = 0; i < N; i++) {
            std::cin >> tmp[i];
            for(int j = 0; j < N; j++) {
                map[i][j] = tmp[i][j] - '0';
            }
        }
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                memorize[i][j] = 99999;
            }
        }
        memorize[0][0] = 0;
        findminRestore(0, 0, 0);
        std::cout << "#" << test << " " << memorize[N - 1][N - 1] << std::endl;
        memset(map, 0, sizeof(int) * 101 * 101);
    }
    return 0;
}


