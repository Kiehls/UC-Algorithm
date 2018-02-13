//
//  BEAKJOON10799(쇠막대기).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/13/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    auto piece = 0;
    string inputStream;
    stack<char> stick;
    
    cin >> inputStream;
    for(int i = 0; i < inputStream.length(); i++) {
        if(inputStream.at(i) == '(') {
            stick.push(inputStream.at(i));
        }
        else {
            stick.pop();
            if(inputStream.at(i - 1) == ')') {
                piece += 1;
            }
            else
                piece += stick.size();
        }
    }
    cout << piece << endl;
    
    return 0;
}

