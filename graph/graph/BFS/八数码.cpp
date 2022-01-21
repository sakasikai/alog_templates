//
//  八数码.cpp
//  BFS
//
//  Created by TonqMaI7 on 2022/1/19.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string state, string ends = "12345678x")
{
    queue<string> q;
    unordered_map<string, int> mp; // 双功能单数据复用：dist[state]；是否访问过 or dist2src

    q.push(state);
    mp[state] = 0;
    
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        
        int k = s.find('x');
        int x = k/3, y =k%3;
        int xv[4] = {-1, 0, 1, 0}, xy[4] = {0, 1, 0, -1};
        
        int dist = mp[s];
        
        if (s == ends) {
            return dist;
        }
        
        for (int i=0; i<4; i++) {
            int nx = x + xv[i];
            int ny = y + xy[i];
            
            if (0<=nx && nx<3 && 0<=ny && ny<3) { // state is valid

                // string深拷贝
                string new_state = ""+s;
                swap(new_state[k], new_state[3*nx+ny]);
                
                if (!mp.count(new_state)){
                    q.push(new_state);
                    mp[new_state] = dist + 1;
                }
            }
        }
    }
    
    // search to end;
    return -1;
}

int main()
{
    char s[2];

    string state;
    for (int i = 0; i < 9; i ++ )
    {
        cin >> s;
        state += *s;
    }

    cout << bfs(state) << endl;

    return 0;
}
