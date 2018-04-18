//
//  BAEKJOON13300(방배정).cpp
//  Algorithm
//
//  Created by Seungsoo on 1/15/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

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
#include <cmath>

using namespace std;

struct shop {
    double range;
    double x;
    double y;
    char name[BUFSIZ];
    int count;
};

vector<shop> pos;

bool compare(shop a, shop b) {
    if(a.range < b.range)
        return true;
    if(a.range == b.range){
        if(a.count > b.count)
            return true;
        if(a.count == b.count) {
            for(int i = 0; i < strlen(a.name); i++) {
                if(a.name[i] < b.name[i]) {
                    return true;
                }
                else if(a.name[i] == b.name[i]){
                    continue;
                }
                else {
                    return false;
                }
            }
        }
    }
    
    return false;
}

int main(int argc, const char *argv[]) {
    int N;
    double x, y;
    cin >> x >> y >> N;
    
    for (int i = 0; i < N; ++i) {
        char name[BUFSIZ];
        double shop_x, shop_y;
        int coupon_count;
        cin >> shop_x >> shop_y >> name >> coupon_count;
        
        double range_x = abs(shop_x - x);
        double range_y = abs(shop_y - y);
        
        double range = (sqrt(pow(range_x, 2) + pow(range_y, 2)) / 100) * 100;
        shop near_shop = {range, shop_x, shop_y, "", coupon_count};
        strcpy(near_shop.name, name);
        
        pos.push_back(near_shop);
    }
    sort(pos.begin(), pos.end(), compare);
    
    for(int i = 0; i < pos.size(); i++) {
        cout << pos[i].x << " " << pos[i].y << " " << pos[i].name << " " << pos[i].count << endl;
    }
    
    return 0;
}

#include <iostream>
#include <cstring>
#define GRADE 7

enum {GIRL, BOY};

int main(int argc, const char * argv[]) {
    // insert code here...
    int num_of_total_student = 0, num_of_max_student = 0;
    std::cin >> num_of_total_student >> num_of_max_student;
    
    int num_of_room = 0, gender, grade;
    int students[2][GRADE];
    memset(students, 0, sizeof(int) * 2 * GRADE);
    
    for(int i = 0; i < num_of_total_student; i++) {
        std::cin >> gender >> grade;
        students[gender][grade] += 1;
    }
    
    for(int i = 0; i < GRADE; i++) {
        num_of_room += students[GIRL][i] / num_of_max_student + students[BOY][i] / num_of_max_student;
        if(students[GIRL][i] % num_of_max_student != 0) {
            num_of_room++;
        }
        if(students[BOY][i] % num_of_max_student != 0) {
            num_of_room++;
        }
    }
    std::cout << num_of_room << std::endl;
    
    return 0;
}

