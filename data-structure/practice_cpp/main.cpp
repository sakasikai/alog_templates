//
//  main.cpp
//  practice_cpp
//
//  Created by TonqMaI7 on 2022/1/16.
//

#include <iostream>

using namespace::std;

void dec2bi(int x){
    cout << "bi("<<x<<")："<<endl;
    for (int i=30; i>=0; i--) {
        int o = x >> i & 1; //看bi(x，i)的第i位数，i从0开始数
        cout << o;
    }
    puts("");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int x = 1 + 4 + 8;
    
    dec2bi(1);
    dec2bi(x);

    // 计算机中数字用补码表示;  正数的补码 == 原码, 负数的补码 == 反码加1
    cout<< "minus = complementary code = ～x + 1" <<endl;
    dec2bi(~x+1);
    dec2bi(-x);
    
    cout<< "inverse code = ～x" <<endl;
    dec2bi(~x);
    
    
    cout<<endl;
    
    return 0;
}
