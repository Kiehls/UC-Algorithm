//
//  SAMSUNG::1::사각지대.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/17/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
//
//  main.cpp
//  Algorithm
//
//  Created by Seungsoo on 1/15/18.
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

#define SIGHT 9

using namespace std;

int testcase;
int W, H;

int unsecuredArea = 0;
int vectorSize = 0;

int map[8][8];
int checkedArea[8][8];

struct camera {
    int x;
    int y;
    deque<int> dir;
    camera(int _x, int _y, deque<int> _dir) : x(_x), y(_y), dir(_dir) {};
};

vector<camera> cctv;

deque<int> cameraDirection(int no) {
    deque<int> t;
    switch(no) {
        case 1:
            t = { 1, 0, 0, 0};
            break;
        case 2:
            t = { 1, 0, 1, 0};
            break;
        case 3:
            t = { 1, 1, 0, 0};
            break;
        case 4:
            t = { 1, 1, 1, 0};
            break;
        case 5:
            t = { 1, 1, 1, 1};
            break;
    }
    return t;
}

int findArea() {
    auto tmp = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(checkedArea[i][j] == 0)
                tmp++;
        }
    }
    return tmp;
}

void checkingArea(int index, int direction) {
    for(int i = 0; i < direction; i++) { //cctv 방향전환
        auto tmp = cctv[index].dir.back();
        cctv[index].dir.pop_back();
        cctv[index].dir.push_front(tmp);
    }
    
    int cur_x = cctv[index].x;
    int cur_y = cctv[index].y;
    
    for(int i = 0; i < 4; i++) {
        if(cctv[index].dir[i] == 1) {
            if(i == 0) { // 상
                for(int i = 0; i < H; i++) {
                    if(cur_x + i >= H)
                        break;
                    if(map[cur_x + i][cur_y] == 6) {
                        checkedArea[cur_x + i][cur_y] = 6;
                        break;
                    }
                    checkedArea[cur_x + i][cur_y] = SIGHT;
                }
            }
            else if(i == 1) { //좌
                for(int i = 0; i < W; i++) {
                    if(cur_y - i < 0)
                        break;
                    if(map[cur_x][cur_y - i] == 6) {
                        checkedArea[cur_x][cur_y - i] = 6;
                        break;
                    }
                    checkedArea[cur_x][cur_y - i] = SIGHT;
                }
            }
            else if(i == 2) { //하
                for(int i = 0; i < H; i++) {
                    if(cur_x - i < 0)
                        break;
                    if(map[cur_x - i][cur_y] == 6)
                        break;
                    checkedArea[cur_x - i][cur_y] = SIGHT;
                }
            }
            else if(i == 3) { //우
                for(int i = 0; i < W; i++) {
                    if(cur_y + i >= W)
                        break;
                    if(map[cur_x][cur_y + i] == 6)
                        break;
                    checkedArea[cur_x][cur_y + i] = SIGHT;
                }
            }
        }
    }
}

void findUnSecuredArea(int index, int direction) {
    if(index >= vectorSize) {
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cout << checkedArea[i][j] << " ";
            }
            cout << endl;
        }
        unsecuredArea = findArea() < unsecuredArea ? findArea() : unsecuredArea;
        return;
    }
    
    if(index != -1) {
        checkingArea(index, direction);
    }
    
    findUnSecuredArea(index + 1, direction);
    findUnSecuredArea(index + 1, direction + 1);
    findUnSecuredArea(index + 1, direction + 2);
    findUnSecuredArea(index + 1, direction + 3);
    
    if(index != -1) {
        //unchecking
    }
    
}

void clear() {
    
}

int main() {
    std::cin >> testcase;
    for (int test = 1; test <= testcase; test++) {
        cin >> W >> H;
        
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> map[i][j];
                if(1 <= map[i][j] && map[i][j] <= 5) {
                    deque<int> tmp = cameraDirection(map[i][j]);
                    cctv.push_back(camera(j, i, tmp));
                }
            }
        }
        vectorSize = (int)cctv.size();
        findUnSecuredArea(-1, 0);
        cout << "#" << test << " " << unsecuredArea << endl;
        clear();
    }
    return 0;
}

/*
 1
 6 4
 3 0 0 0 0 0
 0 0 6 0 0 0
 6 0 0 4 0 0
 0 0 2 0 0 0
 */

