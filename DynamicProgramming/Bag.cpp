// 背包问题大类
#include <bits/stdc++.h>
using namespace std;

// 0-1背包问题
// int dp[1010][1010];
// int w[1010], v[1010]; // w代表重量，v代表价值
// void bag01()
// {
//     int n, W;
//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//         cin >> w[i] >> v[i];
//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j <= W; j++)
//         {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= w[i])
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
//         }
//     cout << dp[n][W] << '\n';
// }
// 一维的0-1背包问题优化
// int dp[1010], w[1010], v[1010];
// void bag01()
// {
//     int n, W;
//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//         cin >> w[i] >> v[i];
//     for (int i = 1; i <= n; i++)
//         for (int j = W; j >= w[i]; j--)
//             dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//     cout << dp[W] << '\n';
// }

// 完全背包问题
// 状态转移方程: f[i][j]=max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]) (k=0,1,2,3,4...)
// const int N = 1010;
// int dp[N][N], w[N], v[N];
// void bag02() // 朴素算法
// {
//     int n, W;
//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//         cin >> w[i] >> v[i];
//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j <= W; j++)
//             for (int k = 0; k * w[i] <= j; k++)
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
//     cout << dp[n][W] << '\n';
// }
// 完全背包问题的优化
// 优化思路:
// f[i][j] = max(f[i-1][j],f[i-1][j-w]+v,f[i-1][j-2w]+2v.....,f[i-1][j-kw]+kv)
// f[i][j-w]=max(          f[i-1][j-w]  ,f[i-1][j-w]+  v.....,f[i-1][j-kw]+(k-1)v)
// 即: f[i][j]=max(f[i-1][j]+f[i][j-w]+v)
// const int N = 1010;
// int dp[N], w[N], v[N];
// void bag02()
// {
//     int n, W;
//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//         cin >> w[i] >> v[i];
//     for (int i = 1; i <= n; i++)
//         for (int j = w[i]; j <= W; j++)
//             dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//     cout << dp[W] << '\n';
// }

// 多重背包问题
// const int N = 105;
// int n, W, dp[N][N], w[N], v[N], s[N];
// void bag03() // 多重背包问题的朴素写法
// {
//     cin >> n >> W;
//     for (int i = 1; i <= n; i++)
//         cin >> w[i] >> v[i] >> s[i];
//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j <= W; j++)
//             for (int k = 0; k * w[i] <= j && k <= s[i]; k++)
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
//     cout << dp[n][W] << '\n';
// }
// 多重背包问题的优化
// 二进制优化
// const int N = 25000;
// int w[N], v[N], dp[N];
// int n, W;
// void bag03()
// {
//     cin >> n >> W;
//     int cnt = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int a, b, s;
//         cin >> a >> b >> s;
//         int k = 1;
//         while (k <= s)
//         {
//             cnt++;
//             w[cnt] = a * k;
//             v[cnt] = b * k;
//             s -= k;
//             k *= 2;
//         }
//         if (s > 0)
//         {
//             cnt++;
//             w[cnt] = a * s;
//             v[cnt] = b * s;
//         }
//     }
//     // 做一次0-1背包问题
//     for (int i = 1; i <= cnt; i++)
//         for (int j = W; j >= w[i]; j--)
//             dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//     cout << dp[W] << '\n';
// }

// 分组背包问题
const int N = 105;
int dp[N], w[N][N], v[N][N], s[N];
int n, W;
void bag04()
{
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> w[i][j] >> v[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= 0; j--)
            for (int k = 1; k <= s[i]; k++)
                if (w[i][k] <= j)
                    dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
    cout << dp[W] << '\n';
}

int main()
{
    // bag01();
    // bag02();
    // bag03();
    bag04();
    return 0;
}
