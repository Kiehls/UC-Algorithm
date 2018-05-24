//
//  약수 진법변환.cpp
//  Algorithm
//
//  Created by Seungsoo on 5/24/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;
int main() {
    int input; cin >> input;
    
    std::string ans = "";
    while(input != 0) {
        if((input % 16) < 10) {
            stringstream ss; ss << input % 16;
            string tmp = ss.str();
            ans = tmp + ans;
            input /= 16;
        }
        else {
            string str(1, ((input % 16) + 87));
            ans = str + ans;
            input /= 16;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int input;
    cin >> input;
    
    for(int i = 1; i <= input; i++) {
        if(input % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
