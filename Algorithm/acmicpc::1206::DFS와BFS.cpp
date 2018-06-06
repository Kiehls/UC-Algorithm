//
//  acmicpc::1206::DFS와BFS.cpp
//  Algorithm
//
//  Created by Seungsoo on 6/3/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <cstring> //memset
#include <stack>
#include <queue>
#include <memory>
#include <limits.h>
#include <sstream>

using namespace std;

int N, M, V;
int vertex1, vertex2;
int map[1001][1001];
bool visited[1001];

void DFS(int start) {
    cout << start << " ";
    visited[start] = true;
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i] && map[start][i] == 1) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    queue<int> que;
    que.push(start);
    visited[start] = true;
    
    while(!que.empty()) {
        int pos = que.front();
        cout << que.front() << " ";
        que.pop();
        for(int i = 1; i <= N; i++) {
            if(!visited[i] && map[pos][i] == 1) {
                que.push(i); visited[i] = true;
            }
        }
    }
}

//int testcase;
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    cin >> N >> M >> V;
    
    for(int i = 0; i < M; i++) {
        std::cin >> vertex1 >> vertex2;
        if(vertex1 == -1 || vertex2 == -1)
            break;
        map[vertex1][vertex2] = map[vertex2][vertex1] = 1;
    }
    DFS(V); cout << endl; memset(visited, false, sizeof(bool) * 1001);
    BFS(V); cout << endl; memset(visited, false, sizeof(bool) * 1001);
}


