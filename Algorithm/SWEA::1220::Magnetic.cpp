//
//  SWEA::1220::Magnetic.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/4/18.
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

int N, M;
int map[100][100];
int blocked = 0;

void Move() {
    int k = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            k = 0;
            if(map[j][i] == 1) {
                for(k = j + 1; k < N; k++) {
                    if(map[k][i] == 2)
                        break;
                }
                if(k == N) {
                    map[j][i] = 0;
                }
            }
            else if(map[j][i] == 2) {
                for(k = j - 1; k >= 0; k--) {
                    if(map[k][i] == 1)
                        break;
                }
                if(k < 0) {
                    map[j][i] = 0;
                }
            }
        }
    }
}
void Find() {
    int bng, end;
    for(int i = 0; i < N; i++) {
        bng = end = 0;
        for(int j = 0; j < N; j++) {
            if(map[j][i]) {
                bng = end;
                end = map[j][i];
                if(bng == 1 && end == 2)
                    blocked++;
            }
        }
    }
}
void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        Move();
        Find();
        
        cout << "#" << test << " " << blocked << endl;
        memset(map, 0, sizeof(int) * 100 * 100);
        blocked = 0;
    }
    
    return 0;
}

