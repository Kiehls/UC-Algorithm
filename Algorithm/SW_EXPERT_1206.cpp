//
//  SW_EXPERT_1206.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/22/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

int num_case;
int num_apartment;
int apartment[1000][1000];

int main() {
    auto view_secured = 0;
    for(int test = 1; test <= 10; test++) {
        std::cin >> num_apartment;
        auto level = 0;
        for(int i = 0; i < num_apartment; i++) {
            std::cin >> level;
            for(int j = 0; j < level; j++) {
                apartment[i][j] = 1;
            }
        }
        for(int i = 0; i < num_apartment; i++) {
            for(int j = 0; j < 1000; j++) {
                if(apartment[i][j] == 0) {
                    break;
                }
                if(apartment[i - 1][j] == 0 && apartment[i - 2][j] == 0 && apartment[i + 1][j] == 0 && apartment[i + 2][j] == 0) {
                    view_secured++;
                }
            }
        }
        std::cout << "#" << test << " " << view_secured << std::endl;
        view_secured = 0;
        memset(apartment, 0, sizeof(int) * 1000 * 1000);
    }
    return 0;
}


