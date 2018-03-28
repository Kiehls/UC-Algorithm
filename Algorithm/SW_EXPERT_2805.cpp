//
//  SW_EXPERT_2805.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/28/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>

int testcase;
int area[50][50];
char tmp[50][50];
int N;
bool isBoundary(int x, int y) {
    return (0 <= x && x <= N) && (0 <= y && y <= N);
}

int find(int x, int y, int k) {
    int farmProfit = 0;
    
    int availMove = k / 2;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int newX = x + i - availMove;
            int newY = y + j - availMove;
            
            if(std::abs(x - newX) + std::abs(y - newY) <= availMove) {
                farmProfit += area[newX][newY];
            }
        }
    }
    
    return farmProfit;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> N;
        
        for(int i = 0; i < N; i++) {
            std::cin >> tmp[i];
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                area[i][j] = tmp[i][j] - '0';
            }
        }
        std::cout << "#" << test << " " << find(N / 2, N / 2, N) << std::endl;
        memset(area, 0, sizeof(int) * 50 * 50);
        memset(tmp, NULL, sizeof(char) *  50 * 50);
    }
    return 0;
}


