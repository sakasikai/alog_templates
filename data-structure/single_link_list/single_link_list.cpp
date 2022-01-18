# include<iostream>

using namespace std;

const int N=100010;
int m;
int head,e[N],ne[N],idx;

void init()
{
    head=-1; // 尾节点指针
    idx=0; // 未使用的，待利用节点
}

void add_head(int x)
{
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

void add(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}

void myremove(int k)
{
    ne[k]=ne[ne[k]];

}
int main()
{
    cin>>m;
    init();
    while(m--)
    {
        char ch;
        cin>>ch;
        if(ch=='H')
        {
            int x;
            cin>>x;
            add_head(x);
        }
        else if(ch=='D')
        {
            int k;
            cin>>k;
            if (!k) head = ne[head]; // 当 k 为 0 时，表示删除头结点
            else myremove(k-1);
        }
        else
        {
            int k,x;
            cin>>k>>x;
            add(k-1, x);
        }
    }
    
    
    for (int i = head; i != -1; i = ne[i] )
        cout<<e[i]<<" ";
    return 0;
}


