//
//  BinarySearch-연습.cpp
//  Algorithm
//
//  Created by Seungsoo on 2/14/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
int find;
int testcase;
int searchCount;
int elementCount;
int elements[200];

int BinarySearch(int lowerBound, int upperBound, int find_element) {
    auto mid = (lowerBound + upperBound) / 2;
    if(lowerBound > upperBound) //조건 확인 부분 잊어먹지 말자!
        return -1;
    if(find_element > elements[mid]) {
        return BinarySearch(mid + 1, upperBound, find_element);
    }
    else if(find_element < elements[mid]) {
        return BinarySearch(lowerBound, mid - 1, find_element);
    }
    else {
        return mid;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    std::cin >> testcase;
    for(int i = 0; i < testcase; i++) {
        std::cin >> elementCount >> searchCount;
        for(int i = 0; i < elementCount; i++) {
            std::cin >> elements[i];
        }
        for(int i = 0; i < searchCount; i++) {
            std::cin >> find;
            std::cout << BinarySearch(0, elementCount - 1, find) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

