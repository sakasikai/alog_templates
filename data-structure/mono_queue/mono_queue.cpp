//
//  mono_queue.cpp
//  data-structure
//
//  Created by TonqMaI7 on 2022/1/15.
//

#include <iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        // 下面的bug，是限制sliding-window的窗口为k；
        // 由于q长度一般不能达到k=3，tt--常发生，q[hh]也就经常变化，而hh几乎不变；
        // 所以sliding-window的左下标是q[hh]，而hh是queue的顶点下标
        // if (i-k+1 >0 && hh < i-k+1) hh++;
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;
         cout << hh<<";"<<q[hh]<<" "<<endl;
        
        // monostone ascending queue for minima of sliding window
        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
        q[ ++ tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1; // reset
    for (int i = 0; i < n; i ++ )
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        q[ ++ tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    return 0;
}
