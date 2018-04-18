//
//  SWEA::4047::영준이의 카드 카운팅.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/9/18.
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

using namespace std;

int testcase;

int card[4][14];
bool ERROR;
char inputStream[1001]; // 카드의 정보 길이가 1 이상 1000이하 +'/0' --> 1001개 선언
vector<int> needCard;

int convert(char a) { // 덱의 종류는 S D H C가 끝 --> 4개의 숫자 반환 끝
    if(a == 'S')
        return 0;
    else if(a == 'D')
        return 1;
    else if(a == 'H')
        return 2;
    else
        return 3;
}

int main() {
    std::cin >> testcase;
    for(int test = 1; test <= testcase; test++) {
        cin >> inputStream;
        for(int i = 0; i < strlen(inputStream); i+= 3) {
            int identifier = convert(inputStream[i]);
            int ten = inputStream[i + 1] - '0';
            int one = inputStream[i + 2] - '0';
            int value = (ten * 10) + one;
            card[identifier][value]++;
        }
        for(int i = 0; i < 4; i++) {
            int needs = 0;
            for(int j = 1; j < 14; j++) {
                if(card[i][j] >= 2)
                    ERROR = true;
                needs += card[i][j];
            }
            needCard.push_back(13 - needs);
        }
        if(ERROR)
            cout << "#" << test << " ERROR" << endl;
        else {
            cout << "#" << test << " " << needCard[0] << " " << needCard[1] << " " <<needCard[2] << " " << needCard[3] << endl;
        }
        ERROR = false;
        memset(card, 0, sizeof(int) * 4 * 14);
        needCard.clear();
        memset(inputStream, NULL, sizeof(char) * 1001);
    }
    return 0;
}

