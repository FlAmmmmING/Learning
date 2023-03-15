#include <bits/stdc++.h>
using namespace std;

// 单调栈问题
// 给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1
// const int N = 1e5 + 3;
// int arr[N], n, tt = 0; // 单调栈
// void func01()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         while (tt && arr[tt] >= x)
//             tt--;
//         if (tt)
//             cout << arr[tt] << ' ';
//         else
//             cout << -1 << ' ';
//         arr[++tt] = x;
//     }
//     cout << '\n';
// }

// 单调队列问题
// 给定一个大小为 n≤106 的数组。有一个大小为 k 的滑动窗口，它从数组的最左边移动到最右边。
// 你只能在窗口中看到 k 个数字。
// 每次滑动窗口向右移动一个位置。

const int N = 1e6 + 3;
int arr[N], q[N], n, k; // 数组q存放的是数组arr的下标
void func02()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int hh = 0, tt = -1;         // hh是队头，tt是队尾
    for (int i = 0; i < n; i++) // i代表这个窗口的头遍历到了哪儿
    {
        // 判断队头是否已经滑出了窗口
        if (hh <= tt && q[hh] < i - k + 1)
            hh++; // 出队
        // 判断队尾是否大于等于进来的这个数，如果大于等于就说明队头元素永远不可能是这个窗口的最小值
        while (hh <= tt && arr[q[tt]] >= arr[i])
            tt--;
        q[++tt] = i; // 入队
        // 特判
        if (i >= k - 1)
            cout << arr[q[hh]] << ' ';
    }
    cout << '\n';
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && arr[q[tt]] <= arr[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            cout << arr[q[hh]] << ' ';
    }
    cout << '\n';
}

// 数组模拟栈和模拟队列

int main()
{
    // func01(); // 单调栈问题'
    func02();
    return 0;
}