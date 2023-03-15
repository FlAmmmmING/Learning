// 字符串哈希模板
// 求区间不相同子串的个数
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int HASH = 1e4 + 7; 
const int MAXN = 2010;
const int SEED = 13331;

ull P[MAXN];
ull S[MAXN];
char str[MAXN];
int ans[MAXN][MAXN];

// 结构体
struct HASHMAP
{
    int head[HASH], next[MAXN], size;
    ull state[MAXN];
    int f[MAXN];
    void init()
    {
        size = 0; // 初始化 size 长度
        memset(head, -1, sizeof(head));
    }

    int insert(ull val, int id)
    {
        int h = val % HASH;                         
        for (int i = head[h]; i != -1; i = next[i]) // 数组模拟单链表
            if (val == state[i])                    // 如果说已经记录了
            {
                int tmp = f[i];
                f[i] = id;
                return tmp;
            }
        // 接下来四行，用数组模拟链表的插入
        f[size] = id;
        state[size] = val;
        next[size] = head[h];
        head[h] = size++;
        return 0;
    }
} H;

int main()
{
    P[0] = 1;
    for (int i = 1; i < MAXN; i++)
        P[i] = P[i - 1] * SEED;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> str;
        int n = strlen(str);
        S[0] = 0;
        // 字符串哈希化
        for (int i = 1; i <= n; i++)
            S[i] = S[i - 1] * SEED + str[i - 1];
        memset(ans, 0, sizeof(ans));
        for (int L = 1; L <= n; L++)
        {
            H.init();
            for (int i = 1; i + L - 1 <= n; i++)
            {
                int l = H.insert(S[i + L - 1] - S[i - 1] * P[L], i);
                // 二维差分
                ans[i][i + L - 1]++;
                ans[l][i + L - 1]--;
            }
        }
        // 二维前缀和
        for (int i = n; i >= 0; i--)
            for (int j = i; j <= n; j++)
                ans[i][j] += ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1];
        // 询问
        int m, u, v;
        cin >> m;
        while (m--)
        {
            cin >> u >> v;
            cout << ans[u][v] << '\n';
        }
    }
    return 0;
}