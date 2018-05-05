//
//  SWEA::1216::회문2.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/5/18.
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

int N, M, L = 100;
char map[100][100];
int maxLength = INT_MIN;
string input;

int findPalindromeRow(int row, int col) {
    int odd = 1, even = 0;
    
    for(int i = 1; i < L / 2; i++) {
        if(col - i >= 0 && col + i < L && map[row][col - i] == map[row][col + i]) {
            odd += 2;
        }
        else
            break;
    }
    for(int i = 0; i < L / 2; i++) {
        if(col - i >= 0 && col + i + 1 < L && map[row][col - i] == map[row][col + i + 1]) {
            even += 2;
        }
        else
            break;
    }
    
    return max(odd, even);
}
int findPalindromeCol(int row, int col) {
    int odd = 1, even = 0;
    
    for(int i = 1; i < L / 2; i++) {
        if(row - i >= 0 && row + i < L && map[row - i][col] == map[row + i][col]) {
            odd += 2;
        }
        else
            break;
    }
    for(int i = 0; i < L / 2; i++) {
        if(row - i >= 0 && row + i + 1 < L && map[row - i][col] == map[row + i + 1][col]) {
            even += 2;
        }
        else
            break;
    }
    
    return max(odd, even);
}

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < L; i++) {
            cin >> input;
            for(int j = 0; j < input.length(); j++) {
                map[i][j] = input[j];
            }
        }
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < L; j++) {
                maxLength = max(maxLength, findPalindromeRow(i, j));
                maxLength = max(maxLength, findPalindromeCol(i, j));
            }
        }
        
        cout << "#" << test << " " << maxLength << endl;
        maxLength = INT_MIN;
        memset(map, NULL, sizeof(char) * 100 * 100);
    }
    
    return 0;
}

