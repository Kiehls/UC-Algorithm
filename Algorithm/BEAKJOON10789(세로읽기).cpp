//
//  BEAKJOON10789(세로읽기).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/12/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char board[5][15];
int main(int argc, const char * argv[]) {
    for(int i = 0; i < 5; i++) {
        std::cin >> board[i];
    }
    for(int j = 0; j < 15; j++) {
        for(int i = 0; i < 5; i++) {
            if(board[i][j] == NULL)
                continue;
            std::cout << board[i][j];
        }
    }
    std::cout << std::endl;
    return 0;
}

