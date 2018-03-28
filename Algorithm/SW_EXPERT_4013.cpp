//
//  SW_EXPERT_4013.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/27/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>


// 2와 6번이 맞다아 있음
int testcase;
int side[2] = {1, -1};
bool checked[4];
std::deque<int> magnet[4];
int multiple[4] = {1, 2, 4, 8};
int K;

void rotate(int pos, int direction) {
    checked[pos] = true;
    for(int i = 0; i < 2; i++) { // 해당 자석의 2번과 오른쪽의 6번, 해당 자석의 6번과 왼쪽의 2번을 xor하여 1이면 다른 극이므로 다른 방향 로테이션
        if( 0 <= pos + side[i] && pos + side[i] <= 3) {
            if(checked[pos + side[i]])
                continue;
            if(side[i] == 1) {
                if((magnet[pos].at(2) ^ magnet[pos + side[i]].at(6)) == 1) {
                    rotate(pos + side[i], direction * -1);
                }
            }
            else {
                if((magnet[pos].at(6) ^ magnet[pos + side[i]].at(2)) == 1) {
                    rotate(pos + side[i], direction * -1);
                }
            }
        }
    }
    
    if(direction == -1) {
        int a = magnet[pos].front();
        magnet[pos].push_back(a);
        magnet[pos].pop_front();
    }
    else {
        int a = magnet[pos].back();
        magnet[pos].push_front(a);
        magnet[pos].pop_back();
    }
}

int get_score() {
    int score = 0;
    for(int i = 0; i < 4; i++) {
        score += magnet[i].at(0) * multiple[i];
    }
    return score;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> K;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 8; j++) {
                auto tmp = 0;
                std::cin >> tmp;
                magnet[i].push_back(tmp);
            }
        }
        int item, direction;
        for(int i = 0; i < K; i++) {
            std::cin >> item >> direction;
            rotate(item - 1, direction);
            memset(checked, false, sizeof(bool) * 4);
        }
        std::cout << "#" << test << " " << get_score() << std::endl;
        for(int i = 0; i < 4; i++)
            magnet[i].clear();
    }
    return 0;
}


