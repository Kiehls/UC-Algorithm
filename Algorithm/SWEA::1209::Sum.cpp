//
//  SWEA::1209::Sum.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/26/18.
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
#include <functional>

using namespace std;

int N;

int _max = INT_MIN;
int map[100][100];

vector<int> ans;
int diagonal = 0;
int diagoanl_reverse = 0;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //cin >> testcase;
    
    for(int test = 1; test <= 10; test++) {
        cin >> N;
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                cin >> map[i][j];
            }
        }
        int sum_row = 0;
        int sum_col = 0;
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                if(i == j)
                    diagonal += map[i][j];
                if(i + j == 99)
                    diagoanl_reverse += map[i][j];
                sum_row += map[i][j];
            }
            ans.push_back(sum_row);
            sum_row = 0;
        }
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                sum_col += map[j][i];
            }
            ans.push_back(sum_col);
            sum_col  = 0;
        }
        sort(ans.begin(), ans.end());
        _max = max(max(diagoanl_reverse, diagonal), ans.back());
        
        cout << "#" << test << " " << _max << endl;
        memset(map, 0, sizeof(int) * 100 * 100);
        ans.clear();
        diagoanl_reverse = diagonal = 0;
    }
    return 0;
}




