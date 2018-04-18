//
//  SWEA::2115::벌꿀채취.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/12/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <memory>
#include <limits.h>

using namespace std;

int testcase;
int N, M, C;

int map[10][10];
int profit[10][10];

int makePairPrice(vector<int> v, int idx, int sum, int price) {
    if(sum > C)
        return 0;
    if(idx == v.size())
        return price;
    
    int tprice1 = makePairPrice(v, idx + 1, sum, price);
    int tprice2 = makePairPrice(v, idx + 1, sum + v[idx], price + (int)pow(v[idx], 2));
    
    return tprice1 > tprice2 ? tprice1 : tprice2;
}

void findMaximunProfit(int row, int col) {
    vector<int> t;
    for(int i = 0; i < M; i++)
        t.push_back(map[row][col + i]);
    profit[row][col] = makePairPrice(t, 0, 0, 0); // 벌꿀의 조합에서 나올 수 있는 최대값 구해서 배열에 저장
}

int findDiffMax(int row, int col) {
    auto _max = 0;
    for(int j = col + M; j < N; j++) { //같은 행에 있는 최대값 찾기
        _max = profit[row][j] > _max ? profit[row][j] : _max;
    }
    for(int i = row + 1; i < N; i++) { //다른 행열에 있는 최대값 찾기
        for(int j = 0; j < N; j++) {
            _max = profit[i][j] > _max ? profit[i][j] : _max;
        }
    }
    return _max;
}

int findMax() {
    int _max = INT_MIN;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - M + 1; j++) {
            auto tmp = profit[i][j] + findDiffMax(i, j); // 배열에서 제일큰 값 + 이를 제외한 나머지 최대값 찾기
            _max = tmp > _max ? tmp : _max;
        }
    }
    return _max;
}

void clear() {
    memset(map, 0, sizeof(int) * 10 * 10);
    memset(profit, 0, sizeof(int) * 10 * 10);
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        cin >> N >> M >> C;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N - M + 1; j++) {
                findMaximunProfit(i, j);
            }
            profit[i][N - 1] = (int)pow(map[i][N - 1], 2);
        }
        
        auto sum = findMax();
        
        cout << "#" << test << " " << sum << endl;
        clear();
    }
    return 0;
}

