//
//  BFS-연습.cpp
//  Algorithm
//
//  Created by Seungsoo on 2/14/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//
#include <iostream>
#include <queue>

int map[31][31];
bool visit[30];
int testcase;
int vertex1, vertex2, start, vertexCount;
void BFS(int start) {
    std::queue<int> queue;
    visit[start] = 1;
    queue.push(start);
    
    while(!queue.empty()) {
        auto standard = queue.front();
        std::cout << queue.front() << " ";
        queue.pop();
        for(int i = 1; i <= vertexCount; i++) {
            if(visit[i] != true && map[standard][i] == 1) {
                queue.push(i);
                visit[i] = true;
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    std::cin >> testcase >> vertexCount >> start;
    for(int i = 0; i < testcase; i++) {
        for(int i = 0; ; i++) {
            std::cin >> vertex1 >> vertex2;
            if(vertex1 == -1 || vertex2 == -1)
                break;
            map[vertex1][vertex2] = map[vertex2][vertex1] = 1;
        }
    }
    BFS(start);
    return 0;
}

