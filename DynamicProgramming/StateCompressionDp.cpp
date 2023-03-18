#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 状态压缩Dp

// 蒙德里安的梦想
// 求把 N×M 的棋盘分割成若干个 1×2 的长方形，有多少种方案。
// 例如当 N=2，M=4 时，共有 5 种方案。当 N=2，M=3 时，共有 3 种方案。
// 当 N = 0, M = 0 时，表示样例终止，无需处理

// const int N = 12, M = 1 << N;
// int n, m;
// ll dp[N][M]; // 不开？？见祖宗
// bool st[M];

// void SCdp01()
// {
//     while(cin >> n >> m, n || m) {
//         // 先初始化 dp ,将 dp 置为 0
//         memset(dp, 0, sizeof(dp));
//         for (int i = 0; i < (1 << n); i++) { // 状态压缩枚举
//             int cnt = 0; // 用来枚举当前列，一共有多少个连续的0
//             st[i] = true;
//             for (int j = 0; j < n; j++) 
//                 if ((i >> j) & 1) { // 这一位是1
//                     if (cnt & 1) st[i] = false;
//                     cnt = 0;
//                 }
//                 else cnt++;
//             if (cnt & 1) st[i] = false; // 假设(i >> j) & 1没有触发
//         }
//         // for (int i = 0; i < (1 << n); i++) cout << st[i] << ' ';
//         // cout << '\n';


//         // 开始dp
//         // 能够转移的条件:
//         // 不存在重叠的1: j & k == 0;
//         // 不存在连续奇数个0，st[j | k] == true
//         dp[0][0] = 1;
//         for (int i = 1; i <= m; i++) 
//             for (int j = 0; j < 1 << n; j++) 
//                 for (int k = 0; k < 1 << n; k++)
//                     if ((j & k) == 0 && st[j | k])   
//                         dp[i][j] += dp[i - 1][k];
//         cout << dp[m][0] << '\n';
//     }
// }


// 给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。
// Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。
// dp[i, j] 表示：所有从 0 走到 j，中间走过所有点是i的路径。 eg：i = (111101)
const int N = 21, M = 1 << N, INF = 0x3f3f3f3f;
int dp[M][N], w[N][N], n;
void SCdp02()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j]; // 无向图的邻接矩阵
    // memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = INF; // 初始化dp
    dp[1][0] = 0; // 0 是起点
    for (int i = 0; i < 1 << n; i++) // 开始枚举i的所有情况
        for (int j = 0; j < n; j++) // j表示走到哪一个点
            if (i >> j & 1) // 合法的判断
                for (int k = 0; k < n; k++)
                    if (i >> k & 1) // 合法的判断
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);
    cout << dp[(1 << n) - 1][n - 1] << '\n';
}

int main()
{
    // SCdp01();
    SCdp02(); 
    return 0;
}
