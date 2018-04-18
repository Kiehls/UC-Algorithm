//
//  SWEA::2382::미생물 격리.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/9/18.
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

using namespace std;

int testcase;
int N, K, M;

struct bacteria {
    int y;
    int x;
    int amount;
    int direction;
};
pair<int, int> direction[5] = { {0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
vector<bacteria> bacteria_info; //**

bool iscChemicalizedArea(int x, int y) {
    return x == 0 || y == 0 || x == N - 1 || y == N - 1;
}

int changeDirection(int direction) {
    if(direction == 1)
        return 2;
    else if(direction == 2)
        return 1;
    else if(direction == 3)
        return 4;
    else
        return 3;
}

void moveBacteria(int idx) {
    int new_x = bacteria_info[idx].x + direction[bacteria_info[idx].direction].first;
    int new_y = bacteria_info[idx].y + direction[bacteria_info[idx].direction].second;
    bacteria_info[idx].x = new_x; bacteria_info[idx].y = new_y;
    
    if(iscChemicalizedArea(new_x, new_y)) {
        bacteria_info[idx].amount /= 2;
        bacteria_info[idx].direction = changeDirection(bacteria_info[idx].direction);
    }
}

int findTotalBacteria() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < bacteria_info.size(); j++) { // 박테리아 위치 이동
            if(bacteria_info[j].amount == 0 || bacteria_info[j].direction == 0)
                continue;
            moveBacteria(j);
        }
        
        vector<int> tmp;
        for(int j = 0; j < bacteria_info.size(); j++) {
            if(bacteria_info[j].amount == 0)
                continue;
            tmp.push_back(j);
            
            for(int k = j + 1; k < bacteria_info.size(); k++) { // 같은 위치를 공유하는 군집끼리 vector화
                if(bacteria_info[k].amount == 0)
                    continue;
                if(bacteria_info[j].x == bacteria_info[k].x && bacteria_info[j].y == bacteria_info[k].y) {
                    tmp.push_back(k);
                }
            }
            
            auto max = 0, sum = 0;
            for(int k = 0; k < tmp.size(); k++) {
                if(max < bacteria_info[tmp[k]].amount) {
                    max = bacteria_info[tmp[k]].amount;
                }
                sum += bacteria_info[tmp[k]].amount;
            }
            for(int k = 0; k < tmp.size(); k++) {
                if(max == bacteria_info[tmp[k]].amount) {
                    bacteria_info[tmp[k]].amount = sum;
                }
                else {
                    bacteria_info[tmp[k]].amount = bacteria_info[tmp[k]].direction = bacteria_info[tmp[k]].x = bacteria_info[tmp[k]].y = 0;
                }
            }
            tmp.clear();
        }
    }
    
    auto sum = 0;
    for(int i = 0; i < bacteria_info.size(); i++) {
        sum += bacteria_info[i].amount;
    }
    return sum;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        cin >> N >> M >> K;
        auto x = 0, y = 0, amount = 0, direction = 0;
        for(int i = 0; i < K; i++) {
            cin >> y >> x >> amount >> direction;
            bacteria tmp = { y, x, amount, direction };
            bacteria_info.push_back(tmp);
        }
        cout << "#" << test << " " << findTotalBacteria() << endl;
        bacteria_info.clear();
    }
    return 0;
}

