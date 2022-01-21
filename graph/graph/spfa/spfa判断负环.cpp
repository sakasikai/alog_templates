//
//  spfa判断负环.cpp
//  spfa
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    for (int i = 1; i <= n; i ++ ){ // 不知道负环存在那个（src，dest）路径上
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        if (cnt[t] > n-1) return true;
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) // 指出边的所有端点
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) // 可以更新的，说明j还可能去更新别的点，入队留到后续搜索
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (!st[j]) // 已经在queue里排队了，过滤掉，提高效率
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false; // 不再是求 1..n 的最短路这个标量值了，而是整个图中是否有负环。
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

    int t = spfa();

    if (t) puts("Yes");
    else puts("No");

    return 0;
}

