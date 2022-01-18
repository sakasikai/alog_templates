//
//  最大异或对.cpp
//  trie_tree
//
//  Created by TonqMaI7 on 2022/1/16.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3100010; // 31x1e5；idx自增id的取值空间

int n;
int a[N], son[M][2], idx;


void bruteforce(int []x, N){
    for (int i = 0; i<N; i++) {
        for (int j=0; j<i; j++) {
            res = max(res, i^j) //按位求异或
        }
    }
}

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int &s = son[p][x >> i & 1];
        if (!s) s = ++ idx;
        p = s;
    }
}

int search(int x) //（贪心）从最高位开始往低位搜索，和x的每i位相反的那个公共前缀集合就是 最大异或对所在的集合，搜索到0位时，就得到最优值。
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int s = x >> i & 1;
        if (son[p][!s]) // 存在与第i位相反的分支（前缀）！
        {
            res += 1 << i; // 贡献xor的第i位二进制
            p = son[p][!s]; // 往这个贡献xor的分支下搜索，最后是会搜索到x的最大异或对
        }
        else p = son[p][s]; //不存在，就只能沿着这个branch往下搜索
    }
    return res; // xor的结果，用trie树优化
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i ++ ) res = max(res, search(a[i]));

    printf("%d\n", res);

    return 0;
}
