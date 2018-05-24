//
//  SWEA::4111:무선 단속 카메라.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/24/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring> //memset
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>

using namespace std;

int N, M, L = 4;

int minLength;
vector<int> camera;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N >> M;
        
        for(int i = 0 ; i < N; i++) {
            int tmp; cin >> tmp;
            camera.push_back(tmp);
        }
        sort(camera.begin(), camera.end());
        for(int i = 1; i < camera.size(); i++) {
            camera[i - 1] = camera[i] - camera[i - 1];
        }
        sort(camera.begin(), camera.end());
        for(int i = 0; i < N - M; i++) {
            minLength += camera[i];
        }
        cout << "#" << test << " " << minLength << endl;
        
        camera.clear(); minLength = 0;
    }
    
    return 0;
}

