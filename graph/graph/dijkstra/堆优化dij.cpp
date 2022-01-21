//
//  堆优化dij.cpp
//  Dijkstra
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N]; // Set S in Dij

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c;
    ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> pq; // 默认是 大 根堆
    pq.push({0, 1}); // (dist, nd_idx) pair
    
    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop(); // (minima_dist, nd_idx)
        int t = pair.second;
        
        // cout << t <<" " << pq.size();
        if(st[t]) continue; // 每次只处理V-S中的点，要过滤掉冗余的S中的点
        // V-S中的点，只要被松弛，就会被加进heap，所以会产生冗余点
        // 而根据Dij的贪心策略，当 t作为最小根 从heap中取出来处理时，t就是最优点，
        // st[t]=true, 而后续冗余点要过滤掉，不再处理！
        
        st[t] = true;
        
        for (int j = h[t]; j!=-1; j = ne[j]) {
            if(!st[ e[j] ]){ // e[j]:终点, w[j]:对应j的边权重, j:关联t和e[j]、w[j]
                dist[ e[j] ] = min(dist[e[j]], dist[t] + w[j]);
                pq.push({dist[e[j]], e[j]});
            }
        }
        // cout << "<-" << pq.size() <<endl;
    }
    
    if (dist[n] > 0x3f3f3f3f / 2) {
        return -1;
    }else return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}
