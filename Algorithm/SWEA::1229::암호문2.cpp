//
//  SWEA::1229::암호문2.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/13/18.
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

vector<int> encryption;
int operation;
char operationCode;

int starting, operating;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    //    cin >> testcase;
    testcase = 10;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> M;
            encryption.push_back(M);
        }
        cin >> operation;
        for(int i = 0; i < operation; i++) {
            cin >> operationCode >> starting >> operating;
            switch(operationCode) {
                case 'I':
                    for(int j = 0; j < operating; j++) {
                        cin >> M;
                        encryption.insert(encryption.begin() + starting + j, M);
                    }
                    break;
                    
                case 'D':
                    for(int j = 0; j < operating; j++) {
                        encryption.erase(encryption.begin() + starting);
                    }
                    break;
                default:
                    break;
            }
        }
        cout << "#" << test << " ";
        for(int i = 0 ; i < 10; i++)
            cout << encryption[i] << " ";
        cout << endl;
        encryption.clear();
    }
    return 0;
}

