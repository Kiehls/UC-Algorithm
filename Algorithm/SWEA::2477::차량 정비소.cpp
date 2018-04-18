//
//  SWEA::2477::차량 정비소.cpp
//  Algorithm
//
//  Created by Seungsoo on 4/11/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <memory>
#include <limits.h>

using namespace std;

int testcase;
int N, M, receptionNum, repairNum, K;

int TIME = 0;

struct process {
    int remain;
    int customer;
};

struct customer {
    int number;
    int reception;
    int repair;
    int arrival;
};

int receptionDesk[10];
int repairDesk[10];
customer customerArrival[1001];
queue<customer> receptionWaitingQue;
queue<customer> repairWaitingQue;

process reception[10];
process repair[10];

bool isFinished() {
    for (int i = 1; i <= K; i++) {
        if (customerArrival[i].reception == 0 || customerArrival[i].repair == 0)
            return true;
    }
    return false;
}

void findCustomer() {
    int p = 1;
    while (isFinished()) {
        for (; p <= K; p++) { // 접수 줄 세우기
            if (customerArrival[p].arrival == TIME) {
                receptionWaitingQue.push(customerArrival[p]);
            }
            else
                break;
        }
        
        for (int i = 1; i <= N; i++) {
            reception[i].remain--;
            auto customerNumber = reception[i].customer;
            if (customerNumber != 0 && reception[i].remain <= 0) { // 접수 완료 시 -> 정비 데스크로 이동
                reception[i].customer = 0;
                repairWaitingQue.push(customerArrival[customerNumber]);
                customerArrival[customerNumber].reception = i;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (!receptionWaitingQue.empty() && reception[i].customer == 0) { // 접수 줄에 기달리고 있으며 접수 데스크가 비어있는 경우
                auto customer = receptionWaitingQue.front(); receptionWaitingQue.pop();
                reception[i].customer = customer.number;
                reception[i].remain = receptionDesk[i];
            }
        }
        
        for (int i = 1; i <= M; i++) { //
            repair[i].remain--;
            auto customerNumber = repair[i].customer;
            if (customerNumber != 0 && repair[i].remain <= 0) {
                repair[i].customer = 0;
                customerArrival[customerNumber].repair = i;
            }
        }
        for (int i = 1; i <= M; i++) {
            if (!repairWaitingQue.empty() && repair[i].customer == 0) {
                auto customer = repairWaitingQue.front(); repairWaitingQue.pop();
                repair[i].customer = customer.number;
                repair[i].remain = repairDesk[i];
            }
        }
        TIME++;
    }
}

int find() {
    auto customerSum = 0;
    for (int i = 1; i <= K; i++) {
        if (customerArrival[i].reception == receptionNum && customerArrival[i].repair == repairNum)
            customerSum += i;
    }
    if (customerSum == 0)
        return -1;
    else
        return customerSum;
}
void clear() {
    memset(receptionDesk, 0, sizeof(int) * 21);
    memset(repairDesk, 0, sizeof(int) * 21);
    memset(customerArrival, 0, sizeof(customerArrival));
    memset(reception, 0, sizeof(process) * 10);
    memset(repair, 0, sizeof(process) * 10);
    TIME = 0;
}

int main() {
    std::cin >> testcase;
    for (int test = 1; test <= testcase; test++) {
        cin >> N >> M >> K >> receptionNum >> repairNum;
        for (int i = 1; i <= N; i++)
            cin >> receptionDesk[i];
        for (int i = 1; i <= M; i++)
            cin >> repairDesk[i];
        for (int i = 1; i <= K; i++) {
            cin >> customerArrival[i].arrival;
            customerArrival[i].number = i;
        }
        
        findCustomer();
        
        cout << "#" << test << " " << find() << endl;
        clear();
    }
    return 0;
}

