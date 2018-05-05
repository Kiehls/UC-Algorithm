//
//  SWEA::1926::간단한 369게임.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/18/18.
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

int N;
int main(int argc, const char * argv[]) {
    cin >> N;
    
    string str;
    for(int i = 1; i <= N; i++) {
        str = to_string(i);
        if(str.find("3") != string::npos || str.find("6") != string::npos || str.find("9") != string::npos) {
            for(int i = 0; i < str.length(); i++) {
                if(str[i] == '3' || str[i] == '6' || str[i] == '9') {
                    cout << "-";
                }
            }
            cout << " ";
        }
        else {
            cout << str << " ";
        }
    }
    
    
    return 0;
}


