//
//  main.cpp
//  union_find
//
//  Created by TonqMaI7 on 2022/1/16.
//

#include <iostream>

using namespace std;

const int N = 100010;

int p[N]; // UID自增

int find(int x) // 返回节点指针
{
    if(p[x]!=x) p[x] = find(p[x]); //1.递归返回到是root，要return  2.路径压缩，同时省略了return
    
    return p[x]; // 是root，返回自身指针
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i; // init; pre[root] = root 自连，标记根

    while (m -- )
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M') p[find(a)] = find(b); // root的pre从指向自己，转为另一个root
        else
        {
            if (find(a) == find(b)) puts("Yes"); // identical root
            else puts("No");
        }
    }

    return 0;
}
