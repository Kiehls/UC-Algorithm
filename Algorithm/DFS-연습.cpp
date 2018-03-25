//
//  DFS-연습.cpp
//  Algorithm
//
//  Created by Seungsoo on 2/14/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>

int map[31][31];
int visit[30];
int testcase;
int vertex1, vertex2, start, vertexCount;
void DFS(int start) {
    std::cout << start << " ";
    visit[start] = 1;
    for(int i = 1; i <= vertexCount; i++) {
        if(visit[i] != 1 && map[start][i] == 1) {
            DFS(i);
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
    DFS(start);
    return 0;
}
