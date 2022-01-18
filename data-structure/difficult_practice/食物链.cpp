//
//  main.cpp
//  difficult_practice
//
//  Created by TonqMaI7 on 2022/1/17.
//

#include <iostream>

using namespace std;

const int N = 50010;

// 类比军队
// 带权并查集，每个node维护这到root的权重，这样判断不同节点间关系就可以O(1)时间算出，而不是O(n^2)

int n, m;
int p[N], d[N]; // 19:23; 维护的是dist[x2parent]距离; 路径压缩时更新为dist[x2root]

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]); // find 返回的是 root节点
        d[x] += d[p[x]]; // 递推公式，dist[x2root] <= dist[x2parent]
        p[x] = t; // 路径压缩，parent[x]直接指向root
    }
    return p[x]; // 路径压缩，parent[x]直接指向root
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int res = 0;
    while (m -- )
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res ++ ;
        else
        {
            int px = find(x), py = find(y); //路径压缩时更新为dist[x2root]
            if (t == 1) // same class
            {
                if (px == py && (d[x] - d[y]) % 3) res ++ ; // 相对距离不同，说明不是同一类，冲突！
                else if (px != py)
                {
                    p[px] = py; // px 父指针 指向 py
                    d[px] = d[y] - d[x]; // 根据关系维护dist[x2parent]; 因为算mod3距离，所以正负无所谓
                }
            }
            else // X eat Y
            {
                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x]; // 根据关系维护dist[x2parent];
                }
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
