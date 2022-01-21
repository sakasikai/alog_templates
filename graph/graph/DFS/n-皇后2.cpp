//
//  n-皇后2.cpp
//  DFS
//
//  Created by TonqMaI7 on 2022/1/18.
//

#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N]; // 既用作存储输入数据，又用来代表搜索数据
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    if(u == n){
        for (int i = 0; i < n; i ++ ){
            for (int j = 0; j < n; j ++ )
                cout << g[i][j];
            cout << endl;
        }
            
        cout << endl;
    }
    
    for (int i=0; i<n; i++) { //search line u
        if(!dg[u+i] && !udg[u-i+n] && !col[i]){ // 这个剪枝太漂亮了！
            dg[u+i] = udg[u-i+n] = col[i] = true;
            
            g[u][i] = 'Q';
            dfs(u+1);
            g[u][i] = '.';
            
            dg[u+i] = udg[u-i+n] = col[i] = false;
        }
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '.';

    dfs(0);

    return 0;
}
