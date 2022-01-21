//
//  main.cpp
//  bellman_ford
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <iostream>

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

struct Edge
{
    int a, b, c;
}edges[M];

int n, m, k;
int dist[N];
int last[N];

void bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; i ++ ){
        memcpy(last, dist, sizeof dist); // dest, src, sizeof
        for (int j = 0; j < m; j ++ ){
            
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c); // 防止串联，用last数组来松弛，即更新dist，每条边只更新一次
        }
    }
}
/*
 注意这里和dijstra算法看起来很像，实际上有本质区别。
 dijkstra算法是从最新的最小点t出发更新所有点到起点的距离dist，
 而这里的for循环时把所有边的终点的最短距离更新一次，如果k = 1的话当然跟dijstra没有甚么区别，然而随着k增大，同一点上的dist最小值可能发生变化。
 列如令k = 2的话，k1上面的点可能从k2上面的负数点绕回去，这样一来dist的值也变了。

 至于说为什么把每一条边用不等式刷k次，最后得到的dist就是相映k条件下的值，我不知道，不过我觉得y总不讲话也没必要马上搞明白。
 */

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}
