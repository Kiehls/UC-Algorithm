//
//  BEAKJOON13301(타일장식).cpp
//  Algorithm
//
//  Created by Seungsoo on 1/21/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    int num_of_tiles = 0;
    std::cin >> num_of_tiles;
    
    long long total_length = 0;
    long long tiles[100] = {0, 1, };
    
    for(int i = 2; i <= num_of_tiles; i++) {
        tiles[i] = tiles[i - 1] + tiles[i - 2];
    }
    
    total_length = tiles[num_of_tiles] * 4 + tiles[num_of_tiles - 1] * 2;
    std::cout << total_length << std::endl;
    
    return 0;
}

