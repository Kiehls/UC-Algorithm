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
#include <string>
#include <cmath>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>

using namespace std;

int M;

struct belt {
    int cur;
    int next;
    int way;
    
    belt(int _c, int _n, int _w) : cur(_c), next(_n), way(_w) {};
};

vector<belt> belts;

int main(int argc, const char * argv[]) {
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        int cur, next, way;
        cin >> cur >> next >> way;
        belts.push_back(belt(cur, next, way));
    }
    
    int direction = 0, ratio = 1;
    for(int i = 0; i < belts.size(); i++) {
        direction = (belts[i].way + direction) % 2;
        ratio = (ratio / belts[i].cur) * belts[i].next;
        
    }
    cout << direction << " " << ratio << endl;
    
    return 0;
}



