//
//  n-皇后.cpp
//  DFS
//
//  Created by TonqMaI7 on 2022/1/18.
//

#include <iostream>

using namespace std;

const int N = 10;

int n;
bool row[N], col[N], dg[N * 2], udg[N * 2];
char g[N][N];

void dfs(int x, int y, int s) // s表示搜索到了多少Q，用来判断结尾
{
    if (s > n) return;
    if (y == n) y = 0, x ++ ;

    if (x == n) // 枚举完最后一行了，该要停止递归了，并判断输出解
    {
        if (s == n)
        {
            for (int i = 0; i < n; i ++ ) puts(g[i]);
            puts("");
        }
        return; // 回溯
    }
    
    // 搜索有两个路径，不放Q
    g[x][y] = '.';
    dfs(x, y + 1, s); // 不放Q，进行搜索

    // 搜索有两个路径，放Q
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) // 放Q，进行搜索；同时剪枝
    {
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
    }
}

int main()
{
    cin >> n;

    dfs(0, 0, 0);

    return 0;
}
