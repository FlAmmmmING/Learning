#include <bits/stdc++.h>
using namespace std;
// 线性Dp

// 数字三角形
// 给定一个如下图所示的数字三角形，从顶部出发，
// 在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

// const int N = 505, INF = 1e9;
// int dp[N][N], arr[N][N], n;
// void triangle()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= i; j++)
//             cin >> arr[i][j];
//     for (int i = 0; i <= n; i++)
//         for (int j = 0; j <= n + 1; j++)
//             dp[i][j] = -INF;
//     // 这里是从下往上做的dp
//     //  for (int i = 1; i <= n; i++)
//     //      dp[n][i] = arr[n][i];
//     //  for (int i = n - 1; i >= 1; i--)
//     //      for (int j = 1; j <= n; j++)
//     //          dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
//     //  cout << dp[1][1] << '\n';

//     // 这里是从上往下做的dp
//     dp[1][1] = arr[1][1];
//     for (int i = 2; i <= n; i++)
//         for (int j = 1; j <= i; j++)
//             dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
//     int res = -INF;
//     for (int i = 1; i <= n; i++)
//     {
//         res = max(res, dp[n][i]);
//     }
//     cout << res << '\n';
// }

// 最长上升子序列
// 给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。
// 状态转移方程 f[i]=max(f[j]+1), j<i&&a[j]<a[i]
// const int N = 1005;
// int arr[N], dp[N], n;
// void subsquence01() // 算法时间复杂度是O(n^2)
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//         dp[i] = 1;
//     }
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j < i; j++)
//             if (arr[i] > arr[j])
//                 dp[i] = max(dp[i], dp[j] + 1);
//     int res = 0;
//     for (int i = 1; i <= n; i++)
//         res = max(res, dp[i]);
//     cout << res << '\n';
// }
// 最长上升子序列优化

// 最长公共子序列
// 给定两个长度分别为 N 和 M 的字符串 A 和 B，求既是 A 的子序列又是 B 的子序列的字符串长度最长是多少。
// const int N = 1010;
// int dp[N][N], n, m;
// char a[N], b[N];
// void subsquence02()
// {
//     cin >> n >> m;
//     // a[0] = 0, b[0] = 0;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     for (int i = 1; i <= m; i++)
//         cin >> b[i];
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//         {//三种情况： 选i不选j、不选i选j、选i选j
//             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             if (a[i] == b[j])
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
//         }
//     cout << dp[n][m] << '\n';
// }
// 最长公共子序列的优化：贪心思想+二分优化
// const int N = 1e5 + 5;
// int arr[N], p[N]; // p[i] 代表——长度为i的递增序列，序列最后一位的数据
// void subsquence02()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     int len = 0;
//     p[0] = -2e9;
//     for (int i = 0; i < n; i++)
//     {
//         int l = 0, r = len;
//         while (l < r)
//         {
//             int mid = l + r + 1 >> 1;
//             if (p[mid] < arr[i])
//                 l = mid;
//             else
//                 r = mid - 1;
//         }
//         len = max(l + 1, len);
//         p[l + 1] = arr[i]; // 更新一下这个下一个递增子序列区间的末尾元素大小
//     }
//     cout << len << '\n';
// }

// 编辑最短距离
// 给定两个字符串 A 和 B，现在要将 A 经过若干操作变为 B，可进行的操作有：
// 删除–将字符串 A 中的某个字符删除。
// 插入–在字符串 A 的某个位置插入某个字符。
// 替换–将字符串 A 中的某个字符替换为另一个字符。
// 现在请你求出，将 A 变为 B 至少需要进行多少次操作
// 状态转移方程:
// 集合属性：f[i,j]代表A的长度为i，B的长度为j的状态， 要的结果是min，我们每次讨论的都是每个字符串末位的情况
// 情况一: 添加元素-> f[i,j] = min(f[i,j],f[i-1,j]+1);
// 情况二：删除元素-> f[i,j] = min(f[i,j],f[i,j-1]+1);
// 情况三: 替换元素-> f[i,j] = min(f[i,j],f[i-1][j-1])+(a[i]==b[i]?1:0);
// const int N = 1003;
// char a[N], b[N];
// int n, m, dp[N][N];
// void theShortestDistance()
// {
//     cin >> n >> a + 1 >> m >> b + 1;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             dp[i][j] = 2e9;
//     for (int i = 1; i <= m; i++)
//         dp[0][i] = i;
//     for (int i = 1; i <= n; i++)
//         dp[i][0] = i;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//         {
//             //下面三个代码可以并在一起写
//             dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
//             dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
//             dp[i][j] = min(dp[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1), dp[i][j]);
//         }
//     cout << dp[n][m] << '\n';
// }

// 一个正整数 n 可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中 n1≥n2≥…≥nk,k≥1。
// 我们将这样的一种表示称为正整数 n 的一种划分。现在给定一个正整数 n，请你求出 n 共有多少种不同的划分方法。
// 本质：完全背包问题
// dp[i,j] = dp[i-1,j] + dp[i-1,j-i] + dp[i-1;j-2i]....
// dp[i,j-i] = dp[i-1,j-i] + dp[i-1,j-2i]....
// 即dp[i][j] = dp[i-1][j] + dp[i][j-i];
// const int mod = 1e9 + 7, N = 1003;
// int dp[N][N], n;
// void divideInteger()
// {
//     cin >> n;
//     for (int i = 0; i <= n; i++)
//     { // 如果说n == 0，那就只有一种方案
//         dp[i][0] = 1;
//     }
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//         {
//             dp[i][j] = dp[i - 1][j] % mod;
//             if (j - i >= 0)
//                 dp[i][j] += dp[i][j - i] % mod;
//         }
//     cout << dp[n][n] << '\n';
// }
// 整数划分的dp数组一维优化
// const int mod = 1e9 + 7, N = 1003;
// int dp[N], n;
// void divideInteger()
// {
//     cin >> n;
//     dp[0] = 1; // 长度为0的时候只有一种方法
//     for (int i = 1; i <= n; i++)
//         for (int j = i; j <= n; j++)
//             dp[j] = (dp[j] + dp[j - i]) % mod;
//     cout << dp[n] << '\n';
// }
int main()
{
    // 数字三角形
    // triangle();

    // subsquence01();
    // subsquence02();
    // theShortestDistance();
    // divideInteger();
    return 0;
}