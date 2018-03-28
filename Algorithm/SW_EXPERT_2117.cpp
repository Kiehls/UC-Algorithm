//
//  SW_EXPERT_2117.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/28/18.
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
int area[21][21];
//std::vector<int> managePrice;
int N, M;
int max_cover;

int calcManagePrice(int area_size) {
    return area_size * area_size + (area_size - 1) * (area_size - 1);
}

int calcCompanyProfit(int numHouse, int area_size) {
    return (M * numHouse) - calcManagePrice(area_size);
}

bool isProfitable(int numHouse, int area_size) {
    return calcCompanyProfit(numHouse, area_size) >= 0 ? true : false;
}

bool isBoundary(int x, int y) {
    return (0 <= x && x <= N) && (0 <= y && y <= N);
}

int find(int x, int y, int k) {
    int numHouse = 0;
    
    
    
    int availMove = 2 * k - 1;
    int sideMove = (availMove - 1) / 2;
    //    for(int i = 0; i < availMove; i++) {
    //        if(isBoundary(x, y + i - sideMove) && area[x][y + i - sideMove]) {
    //            numHouse++;
    //        }
    //    }
    //    for(int i = 0; i < availMove; i++) {
    //        if(isBoundary(x + i - sideMove, y) && area[x + i - sideMove][y]) {
    //            numHouse++;
    //        }
    //    }
    for(int i = 0; i < availMove; i++) {
        for(int j = 0; j < availMove; j++) {
            int newX = x + i - sideMove;
            int newY = y + j - sideMove;
            
            if(std::abs(x - newX) + std::abs(y - newY) < k) {
                if(isBoundary(newX, newY) && area[newX][newY]) {
                    numHouse++;
                }
            }
        }
    }
    
    if(isProfitable(numHouse, k))
        return numHouse;
    
    return 0;
}

void calcMaxCover() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 1; k <= N + 1; k++) {
                max_cover = max_cover > find(i, j, k) ? max_cover : find(i, j, k);
            }
        }
    }
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> N >> M;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                std::cin >> area[i][j];
            }
        }
        //        for(int i = 1; i <= 21; i++) {
        //            managePrice.push_back(calcManagePrice(i));
        //        }
        
        calcMaxCover();
        std::cout << "#" << test << " " << max_cover << std::endl;
        
        memset(area, 0, sizeof(int) * 21 * 21);
        //        managePrice.clear();
        max_cover = 0;
    }
    return 0;
}


