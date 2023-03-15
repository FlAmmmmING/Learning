#include <bits/stdc++.h>
using namespace std;
// 区间dp问题

// 石子合并
// 设有 N 堆石子排成一排，其编号为 1,2,3,…,N。
// 每堆石子有一定的质量，可以用一个整数来描述，现在要将这 N 堆石子合并成为一堆。
// 每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，
// 合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，
// 合并的总代价也不相同。
// 问题是：找出一种合理的方法，使总的代价最小，输出最小代价。

const int N = 305;
int n;
int dp[N][N];
int arr[N], sum[N];
void stone()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i];          // 前缀和
    for (int len = 2; len <= n; len++)         // 枚举长度
        for (int i = 1; i + len - 1 <= n; i++) 
        {
            int l = i, r = i + len - 1;
            dp[l][r] = 1e9;
            for (int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
        }
    cout << dp[1][n] << '\n';
}

int main()
{
    stone();
    return 0;
}