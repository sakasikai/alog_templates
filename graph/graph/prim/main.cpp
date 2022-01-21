//
//  main.cpp
//  Prim
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; // dense
int dist[N];
bool st[N];


int prim()
{
    int res = 0;
    memset(dist, INF, sizeof dist);
    
    for (int i=0; i<n; i++) {
        int t=-1; // find minimal cross-cut
        for (int j=1; j<=n; j++) {
            if(!st[j] && (t==-1 || dist[t] > dist[j])) // dist[j] 是V-S中点到S中点的最短距离
                t=j;
        }
        
        // 第一个点不能做，因为dist全是INF，第一步只是更新最后面的距离！！
        // 即编号j=1的点的所有链出边 由INF更新为w[1][j]
        if (i && dist[t] == INF) return INF;
        
        st[t] = true;
        if(i) res += dist[t];
        
        // update cross-cut
        for (int j=1; j<=n; j++) {
            if(!st[j]) dist[j] = min(dist[j], g[t][j]); // 条件可以没有
        }
    }
    
    return res;
}


int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c); // dup edges
    }

    int t = prim();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}
