//
//  SWEA::2819::격자판의 숫자 이어 붙이기.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/19/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>
#include <string.h>
#include <list>
#include <functional>

using namespace std;

int N, M, L = 4;

int map[4][4];
pair<int, int> direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool dup[9999999];
int _count = 0;

bool isBoarder(int x, int y) {
    return 0 <= x && x < L && 0 <= y && y < L;
}

void findMaximumChoice(int x, int y, int count, string choice) {
    if(count == 7) {
        if(!dup[stoi(choice)]) {
            dup[stoi(choice)] = true;
            _count++;
        }
        return;
    }
    
    choice.append(to_string(map[x][y]));
    
    for(int i = 0; i < 4; i++) {
        int newx = x + direction[i].first;
        int newy = y + direction[i].second;
        
        if(isBoarder(newx, newy)) {
            findMaximumChoice(newx, newy, count + 1, choice);
        }
    }
    return;
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < L; j++) {
                cin >> map[i][j];
            }
        }
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < L; j++) {
                findMaximumChoice(i, j, 0, "");
            }
        }
        cout << "#" << test << " " << _count << endl;
        
        _count = 0;
        memset(map, 0, sizeof(int) * L * L);
        memset(dup, false, sizeof(bool) * 9999999);
    }
    return 0;
}
