//
//  main.cpp
//  kmp
//
//  Created by TonqMaI7 on 2022/1/16.
//

#include <iostream>

using namespace std;

const int N = 100010, M = 1000010; //N为模式串长度，M匹配串长度

int n, m;
int ne[N]; //next[]数组，名字避免和头文件next冲突
char p[N], s[M];  //s为模式串， p为匹配串

int main()
{
    cin >> n >> p+1 >> m >> s+1;  // s+1、p+1 代表数组读取下标从1开始

    ne[0]=-1; // j=0时，ne[0]有意义，p[0]没意义
    for (int i = 2, j = 0; i <= n; i ++ ) // i必须从2开始，即第二个字符
    {
        while (j && p[i] != p[j + 1]) j = ne[j]; // 递归回退
        if (p[i] == p[j + 1]) j ++ ; // j从0开始
        ne[i] = j; // 首字符匹配(ne[i]=1)，值相等(j等于最大 相等前后缀 长度)
    }
    
    for (int i = 1, j = 0; i <= m; i ++ ){
        while(j && s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++; // i++ 在最后
        // j=0,首次进，就只需遍历i,找到匹配，即可让j++

        if(j == n){
            cout << i-n <<" "; //i在匹配子串后面
        }
        
    }
    

    // cout << "\nS  : ";
    // for (int i = 1; i <= m; i ++ ) cout << s[i] <<" ";
    // cout << "\nP  : ";
    // for (int i = 1; i <= n; i ++ ) cout << p[i] <<" ";
    // cout << "\nidx: ";
    // for (int i = 1; i <= n; i ++ ) cout << i <<" ";
    // cout << "\nPMT:";
    // for (int i = 0; i <= n; i ++ ) cout << ne[i] <<" ";
    
    
    return 0;
}
