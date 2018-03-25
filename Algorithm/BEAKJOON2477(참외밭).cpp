//
//  BEAKJOON2477(참외밭).cpp
//  Algorithm
//
//  Created by Seungsoo on 3/4/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <vector>
#include <utility>
int unit_per_area;
std::vector<std::pair<int, int>> area;

int main() {
    std::cin >> unit_per_area;
    for(int i = 0; i < 6; i++) {
        std::pair<int, int> side;
        std::cin >> side.first >> side.second;
        area.push_back(side);
    }
    
    auto max_width = 0, max_height = 0;
    auto max_width_index = 0, max_height_index = 0;
    for(int i = 0; i < area.size(); i++) {
        if(area[i].first == 1 || area[i].first == 2) { // 가로변에 해당되는 변일 경우
            if(max_width < area[i].second) {
                max_width = area[i].second;
                max_width_index = i;
            }
        }
        else if(area[i].first == 3 || area[i].first == 4) { // 세변에 해딩되는 경우
            if(max_height < area[i].second) {
                max_height = area[i].second;
                max_height_index = i;
            }
        }
    }
    auto min_widht = area[(max_height_index + 3) % 6].second , min_height = area[(max_width_index + 3) % 6].second;
    
    auto total_area = max_width * max_height;
    auto part_area = min_widht * min_height;
    
    std::cout << (total_area - part_area)  * unit_per_area << std::endl;
    return 0;
}
