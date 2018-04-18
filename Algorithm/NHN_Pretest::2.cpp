//
//  NHN_Pretest::2.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/17/18.
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

string inputString;

vector<string> tokenizingString(string input) {
    string tmp;
    vector<string> words;
    stringstream stream(input);
    
    while(getline(stream, tmp,' ')) {
        words.push_back(tmp);
    }
    return words;
}

int main() {
    getline(cin, inputString);
    auto words = tokenizingString(inputString);
    
    int vowel = 0, constant = 0;
    int vowel_count = 0, constant_count = 0;
    bool isvowel = false, isconstant = false;
    
    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words[i].length(); j++) {
            if(words[i][j] == 'a' || words[i][j] == 'e' || words[i][j] == 'i' || words[i][j] == 'o' || words[i][j] == 'u') {
                vowel++;
                constant = 0;
            }
            else {
                vowel = 0;
                constant++;
            }
            if(!isvowel && vowel == 2) { // 단어 중 모음이 연속 2개가 두번 나올 경우 방지
                vowel_count++;
                isvowel = true;
            }
            if(isconstant && constant == 3) {
                constant_count++;
                isconstant = true;
            }
        }
        vowel = constant = 0;
        isvowel = isconstant = false;
    }
    cout << vowel_count << endl << constant_count << endl;
    return 0;
}

