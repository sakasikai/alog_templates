//
//  排列数字.cpp
//  DFS
//
//  Created by TonqMaI7 on 2022/1/18.
//

#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N], used[N];

void dfs(int u, int state) // 1.idx to search 2.detect end
{
    if(state == n) {
        for (int i=0; i<n; i++) {
            cout << path[i]<< " ";
        }
        cout << endl;
        return;
    }
    
    
    for (int i=1; i<=n; i++) { //搜索
        if(!used[i]){ // 剪枝
            path[u]= i;
            used[i] = 1;
            dfs(u+1, state+1);
            used[i] = 0; // 回溯
        }
            
    }
}

int main()
{
    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}
