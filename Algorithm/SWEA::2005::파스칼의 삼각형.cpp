//
//  SWEA::2005::파스칼의 삼각형.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/20/18.
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
#include <map>

using namespace std;

int arr[10][10];
int N;

int testcase;
int main(int argc, const char * argv[]) {
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        arr[0][0] = 1;
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(j == 0) {
                    arr[i][j] = 1;
                }
                else
                    arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
        
        cout << "#" << test << endl;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] == 0) {
                    break;
                }
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        
        memset(arr, 0, sizeof(int) * 10 * 10);
    }
    
    return 0;
}


