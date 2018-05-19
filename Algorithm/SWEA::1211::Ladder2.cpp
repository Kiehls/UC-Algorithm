//
//  SWEA::1211::Ladder2.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/17/18.
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

int N, M, L = 10;
int map[100][100];
bool check[100][100];

int length = 1;
vector<pair<int, int>> ans;

// 0 Down 1 Right -1 Left -2 OutofRange

vector<pair<int, int>> startingPoint;

bool isBoarder(int x, int y) {
    return 0 <= x && x < L && 0 <= y && y < L;
}

int isBranch(int x, int y) {
    if(isBoarder(x, y + 1) && map[x][y + 1] == 1 && !check[x][y + 1])
        return 1;
    else if(isBoarder(x, y - 1) && map[x][y - 1] == 1 && !check[x][y - 1])
        return -1;
    else
        return 0;
}

bool findPath(int x, int y, int dir) {
    if(!isBoarder(x, y)) {
        return false;
    }
    
    if(x == L - 1 && map[x][y] == 1) {
        length++;
        return true;
    }
    
    dir = isBranch(x, y);
    check[x][y] = true;
    
    if(dir == 0) { // Down
        length++;
        return findPath(x + 1, y, dir);
    }
    else if(dir == 1) { // Right
        length++;
        return findPath(x, y + 1, dir);
    }
    else if(dir == -1){ // Left
        length++;
        return findPath(x, y - 1, dir);
    }
    
    return false;
}
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second < b.second)
        return true;
    else
        return false;
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < L; j++) {
                cin >> map[i][j];
                
                if(i == 0 && map[i][j] == 1)
                    startingPoint.push_back({i, j});
            }
        }
        
        for(int i = 0; i < startingPoint.size(); i++) {
            if(findPath(startingPoint[i].first, startingPoint[i].second, 0)) {
                ans.push_back({startingPoint[i].second, length});
            }
            length = 0;
            memset(check, false, sizeof(bool) * 100 * 100);
        }
        sort(ans.begin(), ans.end(), compare);
        cout << "#" << test << " " << ans.front().first << endl;
        
        startingPoint.clear();
        memset(map, 0, sizeof(int) * 100 * 100);
        memset(check, false, sizeof(bool) * 100 * 100);
        ans.clear(); length = 0;
    }
    
    return 0;
}


