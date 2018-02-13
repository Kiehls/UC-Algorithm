//
//  BEAKJOON2548(대표자연수).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/2/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>

int natural[20000];
std::vector<std::pair<int, int>> answer;

bool comparator(std::pair<int, int> &a, std::pair<int,int> &b) {
    if(a.first == b.first) {
        return a.second > b.second;;
    }
    return a.first > b.first;
}

int main(int argc, const char * argv[]) {
    int _num_of_natural = 0;
    std::cin >> _num_of_natural;
    
    for(int i = 0; i < _num_of_natural; i++) {
        std::cin >> natural[i];
    }
    for(int i = 0; i < _num_of_natural; i++) {
        int standard = natural[i];
        int tmp = 0;
        for(int j = 0; j < _num_of_natural; j++) {
            tmp += abs(natural[j] - standard);
        }
        std::pair<int, int> pairing(tmp, standard);
        answer.push_back(pairing);
    }
    std::sort(answer.begin(), answer.end(), comparator);
    for(int i  = 0; i < answer.size(); i++) {
        std::cout << answer[i].first << " " << answer[i].second << std::endl;
    }
    std::cout << answer.back().second << std::endl;
    
    return 0;
}

