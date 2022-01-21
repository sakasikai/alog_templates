//
//  main.cpp
//  topological
//
//  Created by TonqMaI7 on 2022/1/20.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10, M = 2*N;
int ans=0x3f3f3f3f, n, a, b; // 每个点搜索一次，能算出每个点的连通块max，然后max最小的即是中心的值，作为输出
int h[N], e[M], ne[M], idx;
int cnt[N];
bool st[N];

void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}


int dfs(int p){ // 返回包含当前节点的子树节点sum
    st[p] = true;
    
    int cnt = 0, ans_s = -1; // 子树节点总数，可能多个连通分量
    for (int i = h[p]; i != -1; i = ne[i] ){
        if (st[e[i]]) continue;
        
        int cnt_t = dfs(e[i]);
        ans_s = max(ans_s, cnt_t);
        cnt += cnt_t;
    }

    ans = min(ans, max(ans_s, n-cnt-1));
    return cnt + 1;
}


int main()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    
    int nn = n-1;
    while (nn -- ) {
        cin >> a >> b;
        add(a, b), add(b, a); // 无向边
    }
    
    dfs(1);
    
    cout << ans <<endl;
    
    return 0;
}


/**
 为什么这题一定要存无向图啊，这里从1开始遍历不是从上往下遍历吗？那只需要从上往下传递信息就行了呀，为啥建一个单向图答案就错了呢
 A：
 因为树的根节点不一定是1号节点，假如我的数据是
 8
 3 1
 3 4
 3 6
 1 2
 1 7
 4 5
 6 8
 那就是3号节点是根节点了，假如是单向图的话， dfs从1开始，经过2和7就停止了，那答案就错了
 */
