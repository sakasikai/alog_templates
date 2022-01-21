//
//  main.cpp
//  Kruskal
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=1e5+10, M=2*1e5+10, INF = 0x3f3f3f3f;
int p[N];
int n, m;

struct Edge{
    int a, b, w;
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}edges[M];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    
    for (int i = 1; i<=n; i ++ ) p[i]=i; // 对节点编号而言的
    
    sort(edges, edges + m);
    
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ ){
        // filter nds already in S
        int a = edges[i].a, b = edges[i].b;
        int ar = find(a), br = find(b);
        if(ar!=br){
         res += edges[i].w;
         p[ar] = br;
         cnt ++ ;
        }
    }
    
    if (cnt < n - 1) return INF; // 最后没形成连通的生成树
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w}; // ? 重边 and 自环？
    }
    
    int t = kruskal();
    
    if (t == INF) puts("impossible");
    else printf("%d\n", t);
    
    return 0;
}
