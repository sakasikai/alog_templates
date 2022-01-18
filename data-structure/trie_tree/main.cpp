//
//  main.cpp
//  trie_tree
//
//  Created by TonqMaI7 on 2022/1/16.
//

#include <iostream>

using namespace std;

const int N = 100010;

// son[N][26]是trie树的静态链表模拟，idx用于构建链表的新节点
// son[N][26]是next_node[p][26],即从当前节点*p，发出了26个节点
// 其值是孩子节点的是指针
int son[N][26], cnt[N], idx; // idx=0，下标是0的点既是root，又是空节点
char str[N];

void insert(char *str)
{
    int p = 0; //从root节点出发
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a'; // asc2int for indexing
        if (!son[p][u]) son[p][u] = ++ idx; // UID；下标是0的点既是root，又是空节点
        p = son[p][u]; // 指针转移，指导下一个节点
    }
    cnt[p] ++ ; // 相当于 e[p]，均是用idx来关联; 而idx是递增的UID，全局唯一，故p指向全局唯一的一个节点！
}

int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    
    for (int i=0; i<10; i++){
        for (int j=0; j<26; j++) {
            cout<<son[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/**
5
I accd
I acbdz
I acbez
I acbdz
Q acbdz
 
 */
