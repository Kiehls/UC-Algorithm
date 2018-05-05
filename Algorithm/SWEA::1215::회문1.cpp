//
//  SWEA::1215::회문1.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/2/18.
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
#include <functional>

// 가로, 세로 각각에 대해서 직선으로만 판단한다.
//

using namespace std;

int N, M;

char map[8][8];
int countPalindrome = 0;

bool Palindrome(deque<char> input) {
    for(int i = 0; i < N / 2; i++) {
        if(input[i] != input[input.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool findRowPalindrome(int row, int idx) {
    deque<char> palindrome;
    for(int i = 0; i < N; i++) {
        palindrome.push_back(map[idx][row + i]);
    }
    
    return Palindrome(palindrome);
}
bool findColPalindrome(int col, int idx) {
    deque<char> palindrome;
    for(int i = 0; i < N; i++) {
        palindrome.push_back(map[col + i][idx]);
    }
    
    return Palindrome(palindrome);
}
int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cin >> map[i][j];
            }
        }
        for(int i = 0 ; i < 8; i++) {
            for(int j = 0; j < 8 - N + 1; j++) {
                if(findRowPalindrome(j, i)) countPalindrome++;
            }
        }
        for(int i = 0 ; i < 8; i++) {
            for(int j = 0; j < 8 - N + 1; j++) {
                if(findColPalindrome(j, i)) countPalindrome++;
            }
        }
        cout << "#" << test << " " << countPalindrome << endl;
        memset(map, NULL, sizeof(char) * 8 * 8);
        countPalindrome = 0;
    }
    return 0;
}



