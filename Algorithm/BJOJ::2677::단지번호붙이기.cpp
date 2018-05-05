//
//  BJOJ::2677::단지번호붙이기.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/21/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>
#include <string.h>

using namespace std;

int N;
int map[25][25];
int start_x, start_y, tmp;
bool check[25][25];

vector<int> ans;

pair<int, int> direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

string row;

bool isBoundary(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

void solution(int x, int y) {
    if(map[x][y] == 0 || check[x][y] || !isBoundary(x, y)) {
        return ;
    }
    check[x][y] = true; tmp++;
    for(int i = 0; i < 4; i++) {
        solution(x + direction[i].first, y + direction[i].second);
    }
    
    if(x == start_x && y == start_y) {
        ans.push_back(tmp);
    }
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> N;
    
    for(int i = 0 ; i < N; i++) {
        cin >>row;
        for(int j = 0; j < row.length(); j++) {
            map[i][j] = row[j] - '0';
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            start_x = i; start_y = j;
            solution(i, j);
            tmp = 0;
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}


