//
//  SW_EXPERT_1953.cpp 탈주범 검거
//  Algorithm
//
//  Created by Seungsoo on 3/31/18.
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
int N, M;
int R, C; // 세로위치 R, 가로위치 C
int L;
int map[52][52];
bool checked[52][52];
int wayPossible[8][4] = {
    {0, 0, 0, 0}, //상 좌 하 우
    {1, 1, 1, 1}, // 1
    {1, 0, 1, 0}, // 2
    {0, 1, 0, 1}, // 3
    {0, 1, 1, 0}, // 4
    {1, 1, 0, 0}, // 5
    {1 ,0, 0, 1}, // 6
    {0, 0, 1, 1}  // 7
};


std::queue<std::pair<int, std::pair<int, int>>> pos;
std::pair<int, int> direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //상 좌 하 우

bool isBoundary(int x, int y) {
    return (0 <= x && x <= M) && (0 <= y && y <= N) && map[y][x] != 0 && !checked[y][x];
}

bool isMove(int a, int b, int way) { // 서로 이어진 터널인지 검사
    if(wayPossible[a][way] && wayPossible[b][(way + 2) % 4])
        return true;
    
    return false;
}

int findPrisoner(int x, int y, int timeCount) { // BFS 알고리즘
    pos.push({timeCount, {x, y}});
    checked[y][x] = true;
    
    while(!pos.empty()) {
        int cur_x = pos.front().second.first;
        int cur_y = pos.front().second.second;
        int cur_count = pos.front().first;
        pos.pop();
        
        for(int i = 0; i < 4; i++) {
            int new_x = cur_x + direction[i].first;
            int new_y = cur_y + direction[i].second;
            int new_count = cur_count + 1;
            
            if(isBoundary(new_x, new_y) && isMove(map[cur_y][cur_x], map[new_y][new_x], i) && new_count <= L) {
                pos.push({new_count, {new_x, new_y}});
                checked[new_y][new_x] = true;
                timeCount++;
            }
        }
    }
    return timeCount;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> N >> M >> R >> C >> L;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                std::cin >> map[i][j];
            }
        }
        std::cout << "#" << test << " " << findPrisoner(C, R, 1) << std::endl;
        memset(map, 0, sizeof(int) * 52 * 52);
        memset(checked, false, sizeof(bool) * 52 * 52);
        while(!pos.empty()) pos.pop();
    }
    return 0;
}


