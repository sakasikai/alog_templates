# 图论

2022.1.18 :tired_face: 有些焦虑啊，别怕，别乱想！勇敢去做！坚持做下来！



## dfs

特点是搜索到的解 有顺序



## bfs

特点是可以求最短搜索统计





## 最短路

![image-20220119144600886](/Users/maiqi/Documents/typora_img/image-20220119144600886.png)

> 均是有向图

> 汇：结尾；dest

> 不超过k条边，BF

> sparse graph（m ~ n）堆优化Dij
>
> dense graph （m  ～ $n^2$）朴素Dij

> 考点：不是证明，考察建图逻辑

 

base：

- 存储选择

  sparse graph：adjacent lists

  dense graph：adjacent matrix

- 



### Dijkstra(naive, heap)

核心思想：

- 已经确定最短距离的点集合 S，补集：S‘

  > S中的点，已经确定对多个dest 最短路径、最短距离

  S和新加点之间叫 横切边

- 对一个新加入的点k，要枚举k的所有横切边，做松弛操作，最后能确定v的最短路
  $$
  k\  \in\  S\quad, v\  \in\  V-S\quad and \quad  edge[k, v]\  exits,\\
  releax(distTo[k] + w[k, v], \quad distTo[v])
  $$

- 数学证明：每个处理好的点，就得到单源最短路

![image-20220119161219936](/Users/maiqi/Documents/typora_img/image-20220119161219936.png)





朴素 Dij；m～n^2；dense；adj matrix

> dijkstra用adj matrix存的时候还需要处理下重边（取最小权重的边，因为求的最短路径），
>
> 如果用邻接表存就不用处理

分两步：

- 遍历`V-S`（没确定最小路的点）中所有点k，选一个DistTo[src]最小的点k，k加入S

- 遍历k的所有指出点（在V-S中），用k做松弛，更新其他横切点的最小距离。

  > 迭代两步，即可得到所有的点的最短路



<img src="/Users/maiqi/Documents/typora_img/image-20220119153747318.png" alt="image-20220119153747318" style="zoom:50%;" />





heap优化

> adj list

![image-20220119154132784](/Users/maiqi/Documents/typora_img/image-20220119154132784.png)

> pri-queue 在每次松弛时，向heap中插入数，可能有m个，即mlogm，而m～n^2，故**mlogm** ～ 2mlogm~**mlogn**



### Bellman-Ford 

对所有节点所有边做releax操作

> 不能有负环，走一圈最短距离就减小一次，陷入死循环

> 用 结构体 存所有边（a, b, w）

<img src="/Users/maiqi/Documents/typora_img/image-20220119173620485.png" alt="image-20220119173620485" style="zoom:67%;" />

> 三角不等式好记忆，src是源点，两边之和大于第三边

> 能求：经过==不超过k条边==的最短距离，即迭代k次 全边松弛计算，
>
> 要求每一次迭代，不能用更新的距离来做松弛计算，即串联更新的情况

![image-20220119191344849](/Users/maiqi/Documents/typora_img/image-20220119191344849.png)





### SPFA

不能有“负环”，其他限制没有

思路：

- bellman-ford中，三角不等式要对每条边都计算，可以剪纸

- 用bfs宽搜优化，即如果dist[b]被变小，那么一定是dist[a]变小，

  所以从src点出发bfs，如果一条边（i, j）被松弛，说明j还可能去更新别的点，

  入队留到后续搜索（未来让它搜索所有后继节点），直到队列为空。

  > 这样，就不需要判断所有边n次了，只需要从src节点bfs搜索**所有真正需要更新的节点**即可。
  >
  > 省去很多计算，提高效率



<img src="/Users/maiqi/Documents/typora_img/image-20220120163436607.png" alt="image-20220120163436607" style="zoom:67%;" />



- 判断负环

  n，m 的图中，如果最短路的边数>n-1，就有负环，反证法即可。

  用spfa做的话，只需要维护dist[i]同时，维护cnt[i]。







### Floyd

> 用 结构体 存所有边（a, b, w）

d[k, i, j]： 从 i 出发到 j 的最短距离，中间只经过编号为1..k 这些点

> 发现可用dp来分解

$$
d[k, i, j]\ =\ min(d[k, i, j], \ \ d[k-1, i, k] + d[k-1, k, j])
$$

ref： [floyd算法图文详解](https://blog.csdn.net/qq_45800977/article/details/106877785?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3.pc_relevant_default&utm_relevant_index=6)

不能有负权回路

邻接矩阵



## 最小生成树

> 无向图

<img src="/Users/maiqi/Documents/typora_img/image-20220120212046791.png" alt="image-20220120212046791" style="zoom:67%;" />



### prim（naive; dense G）

> 横切边：对Graph做一个切分Cut，分成两个节点子集，横跨两个点集的边就是

> 最小生成树：给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。
>
> 由 V 中的**全部 n 个顶点**和 **E 中 n−1 条边**构成的==无向连通子图==被称为 G 的一棵生成树，其中**边的权值之和最小**的生成树被称为无向图 G 的最小生成树。

> 切分定理：在一幅加权图中，给定任意的切分，他的==横切边中的权重最小者==必然属于土图的最小生成树。

<img src="/Users/maiqi/Documents/typora_img/image-20220120222505979.png" alt="image-20220120222505979" style="zoom:67%;" />



### kruskal（sparse G）

<img src="/Users/maiqi/Documents/typora_img/image-20220120223011947.png" alt="image-20220120223011947" style="zoom:67%;" />

> 用并查集判断连通与否，合并连通

> 用 结构体 存所有边（a, b, w），重载比较运算符，便于排序



## 二分图

54



# 排序

> 基操是比较

quick sort

```c++
void quicksort(int q[], int lhs, int rhs){
    if (rhs <= lhs) return; // 递归终点，只有一个数
    
    int i=lhs-1, j=rhs+1, x=q[(lhs + rhs)/2]; //lhs + rhs>>1
    
    while(i < j){ // 循环到 双指针相遇
        do i++; while(q[i]<x); //直到 q[i]
        do j--; while(q[j]>x);
        if(i < j) swap(q[i], q[j]); 
    }
    
    quicksort(q, lhs, j);
    quicksort(q, j+1, rhs);
}
```

merge sort

```c++
void merge_sort(int q[], int ls, int rs){ // rs能取到
    
    if (ls>=rs) return; // 递归终点，只有一个数
    
    int mid = ls+rs>>1;
    
    merge_sort(q, ls, mid);
    merge_sort(q, mid+1, rs);
    
    int k=0, i=ls, j=mid+1;
    
    while(k<=rs-ls){
        if(i>mid){ // 超过左支右界
            tmp[k++]=q[j++];
        }else if(j>rs){ // 超过右支右界
            tmp[k++]=q[i++];
        }else if(q[i]>q[j]){
            tmp[k++]=q[j++];
        }else{
            tmp[k++]=q[i++];
        }
    }
    
    for (int i = ls, j=0; i <= rs; i++, j++) q[i]=tmp[j]; // tmp[] 的下标从0开始

}
```



# 二分搜索

整数二分

> 根据边界，选择对应模板

```c++
// 二分为[lh, mid] [mid+1, rh]
while (lh < rh){
  int mid = lh + rh >>1;
  if(q[mid] >= qry) rh = mid; // 左值；check(mid)=True, 边界包括mid，即mid可能是target
  else lh = mid + 1; // check(mid)=False
}

// 二分为[1, mid-1] [mid, r]
while (lh < rh){
  int mid = lh + rh + 1 >>1;
  if(q[mid] <= qry) lh = mid; // 右值
  else rh = mid - 1;
}
```





浮点二分

> 没有边界问题

```c++
double bisearch(double lh, double rh){
    while(rh-lh>1e-8){ //循环条件
        double mid = (lh + rh)/2;
        if(mid*mid*mid >= n){ // mid >= 3r(n), mid大于真实值，选左边区间；因为指数函数单调，所以可以这么判断！
            rh = mid;
        }else{
            lh = mid;
        }
    }
    return lh;
}


// -1～+1的小数，根号值在边界值外边
// 0~0.001 => x = 0.1 越界了
double m = max(1.0, fabs(n)); // 所以边界不能小于1
printf("%6f", bisearch(-m, m)); // 6位小数
    
```

> 边界lh、rh要选好，因为有时候真实值会跳出想当然的“边界”。
>
> > [0, 0.001] => 三次根号，value = 0.1，跳出想当然边界了





# 前缀和、差分



# 双指针



# 位运算





```c++
// 返回第k位二进制的数，k从0开始
// x：1010
// k：3210 （k从0开始）
n >> k & 1
  
// bi(1)= 0000000000000000000000000000001


// lowbit(x) 返回最后一个1（不一定是最后一位）
// x & (-x) 
// <=> x & (~x+1) 负数x等于x取反加1
int lowbit(int x){  // 返回末尾的1
    return x & -x;
}

// 应用：统计x二进制中“1”的个数
int x, res = 0;
cin >> x;
while(x) x -= lowbit(x), res++; //每次减去最后一位1

```



//看bi(x，k)的第k位数，k从0开始数

![image-20220116194515378](/Users/maiqi/Documents/typora_img/image-20220116194515378.png)

<img src="/Users/maiqi/Documents/typora_img/image-20211216122139573.png" alt="image-20211216122139573" style="zoom:50%;" />



> 计算机三个 码的关系
>
> 补码：计算机中数字用补码表示;  ==正数的补码 \== 原码, 负数的补码 \== 反码加1==
>
> 负数用 补码 表示；-x = ~x+1；之所以加1，是因为0-反码要向上借1位（用加法来实现减法）
>

<img src="/Users/maiqi/Documents/typora_img/image-20211216123437717.png" alt="image-20211216123437717" style="zoom:50%;" />









# 离散化

# 区间合并





# 数据结构



## 链表

<img src="/Users/maiqi/Documents/typora_img/image-20211216202755968.png" alt="image-20211216202755968" style="zoom:50%;" />

数组模拟List

<img src="/Users/maiqi/Documents/typora_img/image-20220115151440756.png" alt="image-20220115151440756" style="zoom:67%;" />



### 单/双链表





stack

queue



## 栈、队列

### 单调栈

优化 离元素最近的最值

> 暴力做法：
>
> ```
> for i in range:
> 	for j =i-1 j>=0; j--:
>   	if (a[j]<a[i]) cout<< a[j]
> ```
>

![image-20220115184056598](/Users/maiqi/Documents/typora_img/image-20220115184056598.png)

### 单调队列

优化 滑动窗口中的最值

![image-20220115185749401](/Users/maiqi/Documents/typora_img/image-20220115185749401.png)





## KMP

S、P 字符串匹配问题

暴搜算法：

枚举S的每个点位 i 得到 S[i: i+len(P)]，对P的每个点位匹配。

冲突时，i‘  =  i+1， j = 0



KMP：

也是枚举S的每个点位 i ，对P的每个点位匹配。

区别在冲突时，i’ 不再回退，j回退到 next(j)；

> 这种更新方法，代表的状态跳跃如下图 a) => b)，j=6 => 4
>
> next(j) 是冲突点前面的**匹配区间**中，公共前缀后缀的最大长度，也是前缀后面点位的index

<img src="https://pic3.zhimg.com/80/v2-03a0d005badd0b8e7116d8d07947681c_1440w.jpg?source=1940ef5c" alt="img" style="zoom:50%;" />

<img src="https://pica.zhimg.com/80/v2-e905ece7e7d8be90afc62fe9595a9b0f_1440w.jpg?source=1940ef5c" alt="img" style="zoom:50%;" />



next数组求法：

pmt右移一位，初始值加上-1，即next数组

<img src="https://pic3.zhimg.com/80/v2-40b4885aace7b31499da9b90b7c46ed3_1440w.jpg?source=1940ef5c" alt="img" style="zoom:50%;" />

求法：

```c++
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
    
    return 0;
}
```





![image-20211217211749202](/Users/maiqi/Documents/typora_img/image-20211217211749202.png)



![next数组.PNG](https://cdn.acwing.com/media/article/image/2020/06/12/31041_97225cdcac-next%E6%95%B0%E7%BB%84.PNG)



i、j 从1开始有意义，如上图所示

ne[0]=-1

```c++
	for (int i = 1, j = 0; i <= m; i ++ ){
        while(j!=0 && s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++; // i++ 在最后
        // j=0,首次进，就只需遍历i,找到匹配，即可让j++
        
        if(j == n){
            cout << i-n <<" "; //i在匹配子串后面
        } 
        
    }



// do KMP
i=j+1=7
s[7]!=p[7],j=ne[6]=4,最长公共前缀后缀为“abab”
j+1=5, p[5]='a',即匹配子串的下一位
// 合理!

S[]: _ a b a b a b a b c a 
P[]: _ a b a b a b c a 
idx: 0 1 2 3 4 5 6 7 8 
PMT:-1 0 0 1 2 3 4 0 1 
  
  
// calculate Next[]
ne[0]=-1;
for (int i = 2, j = 0; i <= n; i ++ ) // i必须从2开始
{
  while (j && p[i] != p[j + 1]) j = ne[j]; //j=0首字符匹配，即使不匹配也不能回退，所以限定排除首字符j=0的情况
  if (p[i] == p[j + 1]) j ++ ;
  ne[i] = j;
}
    
// p和自己匹配，计算最长后缀。
PMT[0]=-1，PMT[1]=0，故从i=2开始 //前后缀必须比匹配区间小1，即区间要>=2，才有意义
i = 2,即p的第二个字符开始，j=0，j+1=1

首次进入，p[2]!=p[1] && j==0,ne[i]=0;合理
  
后面进入，若相等，j++,ne[i]=j,合理
  
i=7时，j+1=5, c!=a, j=ne[4]=2, c!=a, j=ne[ne[4]]=0，合理
  
S[]: _ a b a b a b c a 
P[]: _ a b a b a b c a 
idx: 0 1 2 3 4 5 6 7 8 
PMT:-1 0 0 1 2 3 4 0 1 
  
```



next数组的自循环



## trie tree/字典树

> 字典树 又称**单词查找树**，[Trie树](https://baike.baidu.com/item/Trie树)，是一种[树形结构](https://baike.baidu.com/item/树形结构/9663807)，是一种**哈希树的变种**。
>
> 典型应用是==统计==，排序和保存大量的[字符](https://baike.baidu.com/item/字符)串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
>
> 它的优点是：利用字符串的公共前缀来==减少查询时间，最大限度地减少无谓的字符串比较==，查询效率比哈希树高。

> 高效的 insert和query，是否出现过，以及==出现多少次==，用 cnt[pointer] 表示

![image-20211218184319525](/Users/maiqi/Documents/typora_img/image-20211218184319525.png)



## 并查集

> 数据结构二 26:17 

![image-20211218214049924](/Users/maiqi/Documents/typora_img/image-20211218214049924.png)

![image-20211218214905698](/Users/maiqi/Documents/typora_img/image-20211218214905698.png)



学新事物觉得困难，脑子里一团混乱，可能是人类对未知的恐惧心理

完全理解后，就会觉得有多简单



## 堆

完全二叉树，STL中的优先队列

数组模拟，从1开始

> idx=0 破坏 2x，2x+1 的公式，不用

<img src="/Users/maiqi/Documents/typora_img/image-20211218222252889.png" alt="image-20211218222252889" style="zoom: 50%;" />

以最小堆为例

down: 三个元素中最小的，如果不是顶点（顶点要小于孩子节点），那就顶点 和 最小的儿子节点 交换；不断向下做

up：当前节点，如果比顶点小，就和顶点交换，不断向上做

可用这两个op，实现下面5个大操作



> 变大了 down，变小了 up

![image-20211218223108263](/Users/maiqi/Documents/typora_img/image-20211218223108263.png)

建堆方法：

朴素：n*O(logn)，n插入操作

推荐：O(n) ，从n/2处开始向上遍历，down n/2次；算出来的

![image-20211218225429082](/Users/maiqi/Documents/typora_img/image-20211218225429082.png)



<img src="/Users/maiqi/Documents/typora_img/image-20211218225128358.png" alt="image-20211218225128358" style="zoom:50%;" />

<img src="/Users/maiqi/Documents/typora_img/image-20211218225630333.png" alt="image-20211218225630333" style="zoom:50%;" />





## 哈希

冲突：拉链法、开放寻址法

> **int** k = (x % N + N) % N; // R => -N,N => 0,2N => 0,N
>
> 模数N取质数，冲突最小



### 拉链法

<img src="/Users/maiqi/Documents/typora_img/image-20220117191134353.png" alt="image-20220117191134353" style="zoom: 67%;" />



用数组模拟链表；h[N], e[N], next[N], idx, memset(h, -1, sizeof h);



### 开放寻执法

> 映射k，存储x，如果冲突，k++找到一个空的位置存x

![image-20220117195259196](/Users/maiqi/Documents/typora_img/image-20220117195259196.png)



### 字符串哈希

==方法很厉害；和KMP对应==

快速判断两个 string 是否相等时，就可以用

![image-20220117195240554](/Users/maiqi/Documents/typora_img/image-20220117195240554.png)

> 若哈希映射为0，$(A)^n$就都会映射到0，产生冲突

前缀字符串哈希算出后，可以用公式算出任意字符串的哈希



![image-20220117195638364](/Users/maiqi/Documents/typora_img/image-20220117195638364.png)

> h[R]、h[L-1] 的哈希计算是两个二进制
>
> 左移 h[L-1] R-L+1位，使得和 h[R] 对齐，

![image-20220117195841713](/Users/maiqi/Documents/typora_img/image-20220117195841713.png)

> 然后取模 $2^{64}$，利用技巧，直接类型取 ULL，溢出相当于取模

![image-20220117200318572](/Users/maiqi/Documents/typora_img/image-20220117200318572.png)

> 👆递推公式





## STL

![image-20220106205627147](/Users/maiqi/Documents/typora_img/image-20220106205627147.png)

![image-20220106205515782](/Users/maiqi/Documents/typora_img/image-20220106205515782.png)

![image-20220106205423300](/Users/maiqi/Documents/typora_img/image-20220106205423300.png)

![image-20220106205336508](/Users/maiqi/Documents/typora_img/image-20220106205336508.png)





搜索与图

![image-20220106205836839](/Users/maiqi/Documents/typora_img/image-20220106205836839.png)

![image-20220106210102926](/Users/maiqi/Documents/typora_img/image-20220106210102926.png)

有短有长，BFS能做最短路，DFS不能

DFS俗称爆搜，



![image-20220106220857468](/Users/maiqi/Documents/typora_img/image-20220106220857468.png)

![image-20220106221201160](/Users/maiqi/Documents/typora_img/image-20220106221201160.png)



![image-20220106222250160](/Users/maiqi/Documents/typora_img/image-20220106222250160.png)

![image-20220106222848292](/Users/maiqi/Documents/typora_img/image-20220106222848292.png)



图的dfs

![image-20220114131249915](/Users/maiqi/Documents/typora_img/image-20220114131249915.png)





Topological sort

![image-20220114134605939](/Users/maiqi/Documents/typora_img/image-20220114134605939.png)





# difficult practice

全局变量初始值为0

局部变量不会自动赋值0的



食物链

> // 类比军队
>
> // 带权并查集，每个node维护这到root的权重，这样判断不同节点间关系就可以O(1)时间算出，而不是O(n^2)

> find递归的写法中，要假定，find做路径压缩，**返回root，同时把d[x]从x2p更新为x2root**，然后**在当前递归层** 用递推 实现这个假设即可。

> 维护dist要画下面的图，在union时来初始化

![image-20220117105103673](/Users/maiqi/Documents/typora_img/image-20220117105103673.png)





八数码

> state要用整个棋盘表示，而不能是局部的坐标，因为问题特殊性

![image-20220119085801289](/Users/maiqi/Documents/typora_img/image-20220119085801289.png)





# milestone！



从寒假就要开始，到明年此时，正好一年！只剩一年了？！

acwing

开源-算法可视化 项目

redblobgames

b站讲算法

b站：奇乐编程学院

[计算机中的“进化论” - 遗传算法详解](https://rossning92.github.io/genetic-algorithm)



😄 2021.12.12日

开始 acwing，**算法基础课**
