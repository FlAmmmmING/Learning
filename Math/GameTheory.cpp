// 博弈论
#include <bits/stdc++.h>
using namespace std;
// Nim博弈
// 给定 n 堆石子，两位玩家轮流操作，每次操作可以从任意一堆石子中拿走任意数量的石子（可以拿完，但不能不拿），最后无法进行操作的人视为失败。
// 问如果两人都采用最优策略，先手是否必胜。
// 先手必胜状态：可以进行一次操作，使对手进入先手必败状态
// 先手必败状态：不论如何操作，对手都会进入先手必胜状态
void Nim1()
{
    int n;
    cin >> n;
    int jud;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
            jud = x;
        else
            jud ^= x;
    }
    if (jud)
        cout << "Yes\n";
    else
        cout << "No\n";
}

// Nim博弈的变式
// 台阶——Nim博弈
// 现在，有一个 n 级台阶的楼梯，每级台阶上都有若干个石子，其中第 i 级台阶上有 ai 个石子(i≥1)。
// 两位玩家轮流操作，每次操作可以从任意一级台阶上拿若干个石子放到下一级台阶中（不能不拿）。已经拿到地面上的石子不能再拿，最后无法进行操作的人视为失败。
// 问如果两人都采用最优策略，先手是否必胜。
void Nim2()
{
    int jud = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i % 2)
            jud ^= x;
    }
    if (jud)
        cout << "Yes\n";
    else
        cout << "No\n";
}

// 图论——SG函数
// 集合——Nim博弈
// 给定 n 堆石子以及一个由 k 个不同正整数构成的数字集合 S。
// 现在有两位玩家轮流操作，每次操作可以从任意一堆石子中拿取石子，每次拿取的石子数量必须包含于集合 S，最后无法进行操作的人视为失败。
// 问如果两人都采用最优策略，先手是否必胜

// SG函数(记忆化搜索优化)
int s[105], f[10005]; // f用于记忆化搜索
int n, m;
int SG1(int x)
{
    if (f[x] != -1)
        return f[x];
    unordered_set<int> Set;
    for (int i = 0; i < m; i++)
    {
        int sum = s[i];
        if (x >= sum)
            Set.insert(SG1(x - sum));
    }
    for (int i = 0;; i++)
        if (!Set.count(i))
            return f[x] = i;
}

void Nim3()
{
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof(f));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res ^= SG1(x);
    }
    if (res)
        cout << "Yes\n";
    else
        cout << "No\n";
}

// 图论——SG函数
// 拆分Nim博弈
// 给定 n 堆石子，两位玩家轮流操作，每次操作可以取走其中的一堆石子，然后放入两堆规模更小的石子（新堆规模可以为 0，且两个新堆的石子总数可以大于取走的那堆石子数），最后无法进行操作的人视为失败。
// 问如果两人都采用最优策略，先手是否必胜
int func[105];
int SG2(int x)
{
    if (func[x] != -1)
        return func[x];
    unordered_set<int> Set;
    for (int i = 0; i < x; i++)
        for (int j = 0; j <= i; j++)
            Set.insert(SG2(i) ^ SG2(j));
    for (int i = 0;; i++)
        if (!Set.count(i))
            return func[x] = i;
}
void Nim4()
{
    int n;
    cin >> n;
    memset(func, -1, sizeof(func));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res ^= SG2(x);
    }
    if (res)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
    // Nim1();
    // Nim2();
    // Nim3();
    Nim4();
    return 0;
}