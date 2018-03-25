//
//  BEAKJOON1697(숨바꼭질).cpp
//  Algorithm
//
//  Created by Seungsoo on 3/25/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>

int N, K;
int direction[3] = {2, 1, -1};
int checked[100001];
std::queue<std::pair<int, int>> path;

void BFS(int pos, int count) {
    path.push({pos, 0});
    checked[pos] = true;
    
    while(!path.empty()) {
        auto cur_pos = path.front().first;
        auto cur_count = path.front().second;
        path.pop();
        
        if(cur_pos == K) {
            std::cout << cur_count << std::endl;
            return;
        }
        
        for(int i = 0; i < 3; i++) {
            auto next_pos = 0;
            
            if(i == 0)
                next_pos = cur_pos * direction[i];
            else
                next_pos = cur_pos + direction[i];
            
            if(0 <= next_pos && next_pos <= 100000) {
                if(!checked[next_pos]) {
                    path.push({next_pos, cur_count + 1});
                    checked[next_pos] = true;
                }
            }
        }
    }
    
}

int main() {
    std::cin >> N >> K;
    BFS(N, 0);
    return 0;
}


