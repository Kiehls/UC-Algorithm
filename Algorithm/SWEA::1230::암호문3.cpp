//
//  SWEA::1230::암호문3.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/12/18.
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

deque<int> encryption;
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
            cin >> operationCode;
            switch(operationCode) {
                case 'I':
                    cin >> starting >> operating;
                    for(int j = 0; j < operating; j++) {
                        cin >> M;
                        encryption.insert(encryption.begin() + starting + j, M);
                    }
                    break;
                case 'D':
                    cin >> starting >> operating;
                    for(int j = 0; j < operating; j++) {
                        encryption.erase(encryption.begin() + starting);
                    }
                    break;
                case 'A':
                    cin >> operating;
                    for(int j = 0; j < operating; j++) {
                        cin >> M;
                        encryption.push_back(M);
                    }
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

