#include <bits/stdc++.h>
using namespace std;

// 并查集
// 将两个集合合并
// 询问两个元素是否在一个集合中

// 基本思想：用一棵树来维护集合，树根的编号就是整个集合的编号，每个结点存储它的父节点，p[x]表示x的父节点
// 如何判断树根：令树根 p[x] == x
// 如何求x的集合编号：while (p[x] != x) x = p[x];
// 如何合并两个集合：p[x] 是 x 的集合编号，p[y] 是 y 的集合编号， 令 p[x] = y
// 并查集预处理优化：路径压缩——将所有的结点都指向父结点，达到整个算法复杂度近乎 O(1)

// 并查集应用1：合并集合
// 一共有 n 个数，编号是 1∼n，最开始每个数各自在一个集合中。
// 现在要进行 m 个操作，操作共有两种：
// M a b，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中；
// const int N = 1e5 + 3;
// int p[N]; // 这个数组记录的是每一个元素的父亲结点
// int n, m;
// int find(int x) // 并查集核心操作: 返回这个元素的集合编号——即返回祖宗结点
// {
//     if (p[x] != x)
//         p[x] = find(p[x]);
//     return p[x];
// }
// void func1()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         // 最开始的时候，每一个数组成一个集合
//         p[i] = i;
//     while (m--)
//     {
//         char op[2];
//         int a, b;
//         cin >> op >> a >> b;
//         if (op[0] == 'M')
//             p[find(a)] = find(b); // 集合编号置为相同的
//         else
//         {
//             if (find(a) == find(b))
//                 cout << "Yes\n";
//             else
//                 cout << "No\n";
//         }
//     }
// }

// 给定一个包含 n 个点（编号为 1∼n）的无向图，初始时图中没有边。
// 现在要进行 m 个操作，操作共有三种：
// C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
// Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
// Q2 a，询问点 a 所在连通块中点的数量；

// 相对于传统的并查集，这里需要多给几个数值来维护
const int N = 1e5 + 3;
int p[N], num[N], n, m; // num[N]代表第i个元素的这个集合的元素个数

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void func2()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        num[i] = 1;
        p[i] = i;
    }

    while (m--)
    {
        char op[5];
        cin >> op;
        if (op[0] == 'C')
        {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b))
                continue; // 如果a和b已经在一个集合里面了，直接continue
            num[find(b)] += num[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            int a;
            cin >> a;
            cout << num[find(a)] << '\n';
        }
    }
}

int main()
{
    // func1();
    func2();
    return 0;
}
