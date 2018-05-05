//
//  SWEA::2007::패턴 마디의 길이.cpp
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

string input;
int gap = 0;
bool is = false;

int N;
int main(int argc, const char * argv[]) {
    cin >> N;
    
    for(int test = 1; test <= N; test++) {
        cin >> input;
        
        char standard = input[0];
        
        for(int i = 1; i < input.length(); i++) {
            for(int j = i; j < input.length(); j += i) {
                if(standard == input[j]) {
                    gap = i;
                    if(j + gap >= input.length())
                        is = true;
                }
                else
                    break;
            }
            if(is)
                break;
        }
        cout << "#" << test << " " << gap << endl;
        gap = 0; is = false;
        input.clear();
    }
    
    return 0;
}


