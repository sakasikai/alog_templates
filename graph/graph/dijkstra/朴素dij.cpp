//
//  main.cpp
//  Dijkstra
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; // adj matrix
int dist[N];
bool st[N];

int dijkstra()
{ // 1..n
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    // st[1] = true; // S set
    
    for (int i=0; i<n-1; i++) { // 每次迭代，向S中加一个点，1
        // step 1
        int t=-1;
        for (int j=1; j<=n; j++) {
            if (!st[j] && (t==-1 || dist[j] < dist[t])) { // 一次冒泡，得到最小dist的idx
                t = j;
                // 每次寻找时，t首次赋值给符合条件的j
                // 即 t in Set(j)，不能初始化为t=1 or 2 这样。。。因为1、2可能不属于Set(j)
            }
        }
        
        st[t] = true;
        
        for (int j=1; j<=n; j++) {
            if (!st[j] && dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
            }
        }
        
        // for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    if (dist[n] > 0x3f3f3f / 2) {
        return -1;
    }else return dist[n];
    
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g); // adj matrix
    
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); // m edges a->b weight:c

        g[a][b] = min(g[a][b], c); // simplify duplicate edges
    }

    printf("%d\n", dijkstra());

    return 0;
}
