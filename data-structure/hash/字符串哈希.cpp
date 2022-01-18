//
//  字符串哈希.cpp
//  hash
//
//  Created by TonqMaI7 on 2022/1/17.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

int n, m;
char str[N];
ULL h[N], p[N]; // h[N]代表hash；p[i]代表幂P^i

ULL get(int l, int r)
{
    // p[r-l+1] is P^i
    return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);
    
    // 预处理 字符串哈希前缀
    // str[i]只要不是0就可以，所以按asc2来映射
    p[0]=1;
    for (int i = 1; i <= n; i ++ ){
        p[i] = p[i-1]*P; // p[i] = P^i
        h[i] = h[i-1]*P + str[i]; // h[2] = h[1] * P + str[2]
    }
    

    
    while (m -- )
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}
