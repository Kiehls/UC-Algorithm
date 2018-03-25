//
//  SW_EXPERT_3503.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/18/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

int num_case;
int num_jump_bridge;

int main() {
    std::cin >> num_case;
    for(int i = 0; i < num_case; i++) {
        std::cin >> num_jump_bridge;
        std::vector<int> bridges;
        std::deque<int> arranged_bridges;
        for(int j = 0; j < num_jump_bridge; j++) {
            auto tmp = 0;
            std::cin >> tmp;
            bridges.push_back(tmp);
        }
        std::sort(bridges.begin(), bridges.end());
        for(int j = 0; j < num_jump_bridge; j++) {
            if(j == 0)
                arranged_bridges.push_front(bridges[j]);
            
            else if(j % 2 == 1) {
                arranged_bridges.push_front(bridges[j]);
            }
            else if(j % 2 == 0){
                arranged_bridges.push_back(bridges[j]);
            }
        }
        auto max = 0;
        for(int j = 1; j < num_jump_bridge; j++) {
            max = max < abs(arranged_bridges[j % num_jump_bridge] - arranged_bridges[(j + 1) % num_jump_bridge]) ? abs(arranged_bridges[j % num_jump_bridge] - arranged_bridges[(j + 1) % num_jump_bridge]) : max;
        }
        std::cout << max << std::endl;
    }
    return 0;
}
