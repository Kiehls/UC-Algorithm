//
//  SW_EXPERT_1859.cpp
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
int N;
std::vector<long long> price;

long long calc() {
    long long max_price = 0;
    long long max = price.back();
    for(int i = price.size() - 1; i >= 0; i--) {
        if(max > price[i]) {
            max_price += max - price[i];
        }
        else
            max = price[i];
    }
    return max_price;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        std::cin >> N;
        
        for(int i = 0; i < N; i++) { // input stream
            auto tmp = 0;
            std::cin >> tmp;
            price.push_back(tmp);
        }
        
        std::cout << "#" << test << " " << calc() << std::endl;
        price.clear();
    }
    
    return 0;
}

