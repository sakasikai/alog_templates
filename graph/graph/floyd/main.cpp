//
//  main.cpp
//  Floyd
//
//  Created by TonqMaI7 on 2022/1/18.
//

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ ){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
}

void dbg(){
    for (int i = 0; i <= n; i ++ ){
        for (int j = 0; j <= n; j ++ ){
            if (d[i][j] > INF / 2) cout<< "INF ";
            else cout<<d[i][j] << " ";
        }
        cout<<endl;
    }
}


int main()
{
    scanf("%d%d%d", &n, &m, &Q);

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ ) // 这里要把d[i][i]设置成0，所以就用循环来写了，没用memset。
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    // dbg();

    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c); // 处理重边
    }


    floyd();
    // dbg();
    

    while (Q -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);

        int t = d[a][b];
        if (t > INF / 2) puts("impossible");
        else printf("%d\n", t);
    }

    return 0;
}



/**
 adj matrix将自己到自己的距离初始化为0
 询问可能会问到自身到自身的距离的，所以要初始化为0， 如果不关心自身到自身的距离的话不用。
 
 啥时候跟INF/2比较，啥时候跟INF比较啊 ?
 如下情况：点并不能走到终点；但由于负数边权的存在，终点的距离可能被其他长度是正无穷的距离更新。跟INF / 2比较可以处理这种情况。
 
 */
