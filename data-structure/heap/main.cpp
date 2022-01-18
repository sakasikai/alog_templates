//
//  main.cpp
//  heap
//
//  Created by TonqMaI7 on 2022/1/17.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt; // size of heap

void down(int u) // param is idx of heap
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u)
{
    while (u/2 && h[u] < h[u/2]) { // u/2 > 0; heap idx 不能为0
        swap(h[u], h[u/2]);
        u = u/2;
    }
}


viod operations(int x, int k){
    // init heap
    for (int i = cnt / 2; i; i -- )
        down(i);
    
    // insert
    h[++cnt] = x;
    up(x);
    
    // get minima
    h[1];
    
    // delete minima
    h[1] = h[cnt--];
    down(1);
    
    // delete arbitrary node k； 而第k个插入的数，还需要映射到heap的idx！
    h[k] = h[cnt--];
    down(k); up(k);
    
    // modify arbitrary node k
    h[k] = x;
    down(k); up(k);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
    cnt = n;

    for (int i = n / 2; i; i -- ) down(i);

    while (m -- )
    {
        printf("%d ", h[1]);
        h[1] = h[cnt -- ];
        down(1);
    }

    puts("");

    return 0;
}
