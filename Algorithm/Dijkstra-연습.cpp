//
//  Dijkstra-연습.cpp
//  Algorithm
//
//  Created by Seungsoo on 2/14/18.
//  Copyright © 2018 Seungsoo. All rights reserved.
//

#include <iostream>
#include <cstdlib>

int testcase;
int vertexCount, start, end;
int edgeCount;
int map[101][101];
bool visit[101];
int distance[101];
void Dijkstra(int start, int end) {
    distance[start] = 0;
    for(int i = 0; i < vertexCount; i++) {
        auto min = INT_MAX, idx = 0;
        for(int j = 0; j <= vertexCount; j++) {
            if(!visit[j] && min > map[start][j]) {
                min = map[start][j];
                idx = j;
            }
        }
        visit[idx] = true;
        for(int j = 0; j < vertexCount; j++) {
            if(!visit[j] && distance[idx] > ) {
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    std::cin >> testcase >> vertexCount >> start >> end;
    memset(map, INT_MAX, sizeof(int) * 101 * 101);
    memset(distance, INT_MAX, sizeof(int) * 101);
    for(int i = 0; i < testcase; i++) {
        for(int j = 0; j < edgeCount; j++) {
            auto vertex1 = 0, vertex2 = 0, edge = 0;
            std::cin >> vertex1 >> vertex2 >> edge;
            map[vertex1][vertex2] = edge;
        }
    }
    Dijkstra(start, end);
    return 0;
}

