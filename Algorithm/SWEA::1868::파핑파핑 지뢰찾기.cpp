//
//  SWEA::1868::파핑파핑 지뢰찾기.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/22/18.
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

int selection;
int map[300][300];
char mine[300][300];
bool visite[300][300];
pair<int, int> direction[8] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

bool isBoarder(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int findMine(int x, int y) {
    if(mine[x][y] == '*')
        return 9999;
    
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        int newx = x + direction[i].first;
        int newy = y + direction[i].second;
        
        if(isBoarder(newx, newy)) {
            if(mine[newx][newy] == '*') {
                sum++;
            }
        }
    }
    return sum;
}

void findMinimumSelection(int x, int y) {
    visite[x][y] = true;
    
    for(int i = 0; i < 8; i++) {
        int newx = x + direction[i].first;
        int newy = y + direction[i].second;
        
        if(isBoarder(newx, newy) && map[newx][newy] != 9999) {
            if(!visite[newx][newy] && map[newx][newy] == 0) {
                findMinimumSelection(newx, newy);
            }
            else {
                visite[newx][newy] = true;
            }
        }
    }
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> mine[i][j];
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                map[i][j] = findMine(i, j);
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(map[i][j] == 0 && !visite[i][j]) {
                    findMinimumSelection(i, j);
                    selection++;
                }
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                
                if(!visite[i][j] && mine[i][j] != '*') {
                    selection++;
                }
            }
        }
        cout << "#" << test << " " << selection << endl;
        
        selection = 0;
        memset(map, 0, sizeof(int) * 300 * 300);
        memset(mine, NULL, sizeof(char) * 300 * 300);
        memset(visite, false, sizeof(bool) * 300 * 300);
    }
    
    return 0;
}

