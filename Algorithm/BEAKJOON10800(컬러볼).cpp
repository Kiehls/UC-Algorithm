//
//  BEAKJOON10800(컬러볼).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/13/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

bool comparator(std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.second > b.second;
}

int main(int argc, const char * argv[]) {
    auto ball = 0;
    std::cin >> ball;
    std::vector<std::pair<int, int>> colorball;
    for(int i = 0; i < ball; i++) {
        auto color = 0, size = 0;
        std::cin >> color >> size;
        std::pair<int, int> player(color, size);
        colorball.push_back(player);
    }
    std::vector<std::pair<int, int>> copy_colorball(colorball.begin(), colorball.end());
    std::sort(colorball.begin(), colorball.end(), comparator);
    std::map<int, int> weight;
    
    for(int i = 0; i < ball; i++) {
        weight[colorball[i].second] = 0;
        for(int j = i; j < ball; j++) {
            if(colorball[i].first != colorball[j].first || colorball[i].second > colorball[j].second) {
                weight[colorball[i].second] += colorball[j].second;
            }
        }
    }
    for(auto i = 0; i < ball; i++) {
        std::cout << weight[copy_colorball[i].second] << std::endl;
    }
    
    return 0;
}

