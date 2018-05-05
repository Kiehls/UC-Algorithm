//
//  SWEA::3499::퍼펙트 셔플.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/23/18.
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

using namespace std;

string input;
int N, size;
vector<string> cards;
vector<string> _front;
vector<string> _end;

int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> testcase;
    
    for(int test = 1; test <= testcase; test++) {
        cin >> N;
        for(int i = 0 ; i < N; i++) {
            cin >> input;
            cards.push_back(input);
        }
        
        size = N % 2 == 1 ? N / 2 + 1 : N / 2;
        for(int i = 0; i < size; i++) {
            _front.push_back(cards[i]);
        }
        for(int i = size; i < N; i++) {
            _end.push_back(cards[i]);
        }
        
        cout << "#" << test << " ";
        for(int i = 0; i < size; i++) {
            if(i == size - 1 && N % 2 == 1) {
                cout << _front[i];
            }
            else
                cout << _front[i] << " " << _end[i] << " ";
        }
        cout << endl;
        
        cards.clear();
        _front.clear();
        _end.clear();
    }
    
    return 0;
}


