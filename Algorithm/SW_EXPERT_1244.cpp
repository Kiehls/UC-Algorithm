//
//  SW_EXPERT_1244.cpp
//  Algorithm
//
//  Created by Seungsoo on 3/24/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>

int num_case;
int input, max;
int change_count;
bool isChecked[100][1000000];
std::vector<int> input_list;

int numerization() {
    auto tmp = 0;
    for(int i = 0; i < input_list.size(); i++) {
        tmp += input_list[i] * pow(10, input_list.size() - i - 1);
    }
    return tmp;
}

void swap(int point1, int point2) {
    int a = input_list[point1];
    int b = input_list[point2];
    
    input_list[point1] = b;
    input_list[point2] = a;
}

void DFS(int count) {
    if(count == change_count) {
        max = max < numerization() ? numerization() : max;
        return;
    }
    
    if(isChecked[count][numerization()])
        return;
    isChecked[count][numerization()] = true;
    
    for(int i = 0; i < input_list.size(); i++) {
        for(int j = i + 1; j < input_list.size(); j++) {
            swap(i, j);
            DFS(count + 1);
            swap(i, j);
        }
    }
    return;
}

int main() {
    std::cin >> num_case;
    for(int testcase = 1; testcase <= num_case; testcase++) {
        std::cin >> input >> change_count;
        while(input / 10 != 0) {
            input_list.push_back(input % 10);
            input /= 10;
        }
        input_list.push_back(input);
        std::reverse(input_list.begin(), input_list.end());
        DFS(0);
        std::cout << "#" << testcase << " " << max << std::endl;
        memset(isChecked, false, sizeof(bool) * 100 * 1000000);
        input_list.clear();
        max = 0;
    }
    return 0;
}


