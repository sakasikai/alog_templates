//
//  走迷宫.cpp
//  BFS
//
//  Created by TonqMaI7 on 2022/1/19.
//

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N]; //d = -1 代表未走过； d!=-1代表距离

int bfs(){
    memset(d, -1, sizeof d);
    queue<PII> q;
    
    q.push({0,0});
    d[0][0] = 0;
            
    // 用 花扩号 init
    int xv[4] = {-1, 0, 1, 0}, xy[4] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        PII pair = q.front();
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nex = pair.first + xv[i];
            int ney = pair.second + xy[i];
            
            if (0<=nex && nex<n && 0<=ney && ney<m
                && !g[nex][ney] && d[nex][ney]==-1) {
                
                q.push(make_pair(nex, ney));
                d[nex][ney] = d[pair.first][pair.second] + 1;
                
                cout << nex << " " << ney << ";" << d[nex][ney] <<endl;
                
                if(nex == n -1 && ney == m-1){
                    return d[nex][ney];
                }
            }
        }
    }
    
    // 全搜索完再退出也行
//    if(nex == n -1 && ney == m-1){
//        return d[nex][ney];
//    }
    return -1;
    
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

