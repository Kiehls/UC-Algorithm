//
//  BEAKJOON10163(색종이).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/8/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
int grid[101][101];
int main(int argc, const char * argv[]) {
    int Npaper = 0, sx, sy, width, height;
    std::cin >> Npaper;
    
    for(int i = 1; i <= Npaper; i++) {
        std::cin >> sx >> sy >> width >> height;
        for(int j = sy; j < height + sy; j++) {
            for(int k = sx; k < width + sx; k++) {
                grid[j][k] = i;
            }
        }
    }
    for(int i = 1; i <= Npaper; i++) {
        int sum = 0;
        for(int j = 0; j < 101; j++) {
            for(int k = 0; k < 101; k++) {
                if(grid[j][k] == i) {
                    sum++;
                }
            }
        }
        std::cout << sum << std::endl;
    }
    
    return 0;
}

