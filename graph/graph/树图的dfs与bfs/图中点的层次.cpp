//
//  图中点的层次.cpp
//  spfa
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;


const int N = 1e5+10;
int h[N], e[N], ne[N], idx;
int n, m, a, b;
int dist[N];

void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}


int bfs(int u){
    queue<int> q;
    q.push(u);
    
    memset(dist, -1, sizeof dist);
    dist[u]=0;
    
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        
        if (p == n) {
            return dist[n];
        }
        
        for (int i = h[p]; i!=-1; i=ne[i]) {
            int j = e[i];
            if (dist[j]==-1) { // 不走回头路
                q.push(j);
                dist[j] = dist[p] + 1;
            }
        }
    }
    
    return -1;
}


int main()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof h);

    while (m -- ) {
        cin >> a >> b;
        add(a, b); // 无向边
    }
     
    cout << bfs(1) <<endl;
    
    return 0;
}
