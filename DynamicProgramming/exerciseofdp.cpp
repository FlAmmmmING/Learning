//牛客寒假冬季训练营4，D
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f, MOD = 998244353;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
// ——————————————————————————————————————————————————————————————————————————————————————————————————————
// ——————————————————————————————————————————————————————————————————————————————————————————————————————
// ——————————————————————————————————————————————————————————————————————————————————————————————————————
// ——————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 5000 + 5;
int n, m;
ll dpf[N][N], dpr[N][N];
ll Af[N], Ar[N];
ll w[N], v[N];

void getDP(ll dp[][N]) // DP函数,DP数组:从物品1~n，重量从0~m,dpmax=dp[n][m];
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    // 以下获得dpf和dpr的数值
    getDP(dpf);
    reverse(w + 1, w + 1 + n);
    reverse(v + 1, v + 1 + n);
    getDP(dpr);
    reverse(w + 1, w + 1 + n);
    reverse(v + 1, v + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        // 重置
        memset(Af, 0, sizeof(Af));
        memset(Ar, 0, sizeof(Ar));
        for (int j = 1; j <= m; j++)
            Af[j] = max(Af[j - 1], dpf[i - 1][j]); // 得到在重量为j,只能取前i-1项物品的时候，我能获得的最大收益Af[j]
        for (int j = 1; j <= m; j++)
            Ar[j] = max(Ar[j - 1], dpr[n - i][j]); // 得到在重量为j，只能取后n-i项物品的时候，我能获得的最大收益Ar[j];
        ll Vmax = 0, Vmaxi = 0;                    // Vmax是强制不选i的时候所获得的最大收益,Vmaxi是强制选了i的时候所获得的最大收益
        for (int j = 0; j <= m; j++)
        {
            Vmax = max(Vmax, Af[j] + Ar[m - j]); // 获得了去除了i的Vmax最大收益
            // 以下获得Vmaxi最大收益
            if (m - j - w[i] >= 0)
            {
                Vmaxi = max(Vmaxi, Af[j] + Ar[m - j - w[i]] + v[i]); // 获得强制加了i的Vmaxi最大收益
            }
        }
        cout << max(0ll, Vmax - Vmaxi + 1ll) << '\n';
    }
    return 0;
}