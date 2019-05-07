//
//  main.cpp
//  WeightedGraphs
//
//  Created by John Lime on 2019/05/04.
//  Copyright © 2019 Mioto Takahashi. All rights reserved.
//

#include <iostream>

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M [MAX][MAX];

int prim(){
    int u, minv;
    int d[MAX], p[MAX], color[MAX];
    
    for(int i=0; i<n; i++){
        d[i]=INFTY;
        p[i]=-1;
        color[i]=WHITE;
    }
    d[0] =0;
    while(1){
        minv=INFTY;
        u=-1;
        for(int i=0; i<n; i++){
            if(minv>d[i] && color[i]!=BLACK){
                u=i;
                minv=d[i];
            }
        }
        if (u==-1)break;
        color[u]=BLACK;
        for(int v=0; v<n; v++){
            if(color[v]!=BLACK && M[u][v]!=INFTY){
                if(d[v]>M[u][v]){
                    d[v]=M[u][v];
                    p[v]=u;
                    color[v]=GRAY;
                }
            }
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        if(p[i]!=-1)sum +=M[i][p[i]];
    }
    return sum;
}

void dijkstra(){
    int minv;
    int d[MAX], color[MAX];
    for(int i=0; i<n; i++){
        d[i]=INFTY;
        color[i]=WHITE;
    }
    d[0]=0;
    color[0]=GRAY;
    while(1){
        minv=INFTY;
        int u=-1;
        for(int i=0; i<n; i++){
            if(minv>d[i] && color[i] !=BLACK){
                u=i;
                minv=d[i];
            }
        }
        if(u==-1)break;
        color[u]=BLACK;
        for(int v=0; v<n; v++){
            if(color[v]!=BLACK && M[u][v]!=INFTY){
                if(d[v]>d[u] + M[u][v]){
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        std::cout << i << " " << (d[i] == INFTY ? -1:d[i]) << std::endl;
    }
}

//int main(int argc, const char * argv[]) {
//    std::cin >> n;
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            int e; std::cin>>e;
//            M[i][j] = (e==-1)? INFTY:e;
//        }
//    }
//    std::cout << prim() << std::endl;
//    return 0;
//}

int main(int argc, const char * argv[]) {
    std::cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M[i][j] = INFTY;
        }
    }
    int k, c, u, v;
    for(int i=0; i<n; i++){
        std::cin >> u >> k;
        for(int j=0; j<k; j++){
            std::cin >> v >> c;
            M[u][v] = c;
        }
    }
    dijkstra();
    return 0;
}
