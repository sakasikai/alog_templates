//
//  拉链法.cpp
//  hash
//
//  Created by TonqMaI7 on 2022/1/17.
//


#include <cstring>
#include <iostream>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++ ; // h[k]指向的节点代表一个hash表中的一个插入，多个插入都映射到k的话，代表着冲突，影响存在性的判断！
}

bool find(int x)
{
    int k = (x % N + N) % N; // R => -N,N => 0,2N => 0,N
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I') insert(x);
        else
        {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}

