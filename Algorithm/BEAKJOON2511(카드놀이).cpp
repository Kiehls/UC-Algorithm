//
//  BEAKJOON2511(카드놀이).cpp
//  Algorithm
//
//  Created by Seungsoo on 2/11/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
int card_a[10], card_b[10];
int score_a, score_b;
char winner;
#include <iostream>
int main(int argc, const char * argv[]) {
    
    for(int i = 0; i < 10; i++) {
        std::cin >> card_a[i];
    }
    for(int i = 0; i < 10; i++) {
        std::cin >> card_b[i];
    }
    
    for(int i = 0; i < 10; i++) {
        if(card_a[i] > card_b[i]) {
            score_a += 3;
            winner = 'A';
        }
        else if(card_a[i] < card_b[i]) {
            score_b += 3;
            winner = 'B';
        }
        else {
            score_a++;
            score_b++;
        }
    }
    std::cout << score_a << " " << score_b << std::endl;
    if(score_a == 10 && score_b == 10)
        std::cout << 'D' << std::endl;
    else if(score_a > score_b)
        std::cout << 'A' << std::endl;
    else if(score_a < score_b)
        std::cout << 'B' << std::endl;
    else
        std::cout << winner << std::endl;
    
    return 0;
}
