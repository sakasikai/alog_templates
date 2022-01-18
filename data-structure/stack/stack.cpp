//
//  stack.cpp
//  data-structure
//
//  Created by TonqMaI7 on 2022/1/15.
//

#include <iostream>

using namespace std;

const int N = 100010;

int m;
int stk[N], tt;

int main()
{
    cin >> m;
    while (m -- )
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            stk[ ++ tt] = x; // push
        }
        else if (op == "pop") tt -- ;
        else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;
        else cout << stk[tt] << endl; // top of stack
    }

    return 0;
}