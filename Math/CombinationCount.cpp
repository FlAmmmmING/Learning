// 组合计数
// 组合计数公式1: aCb = (a-1)Cb + (a-1)C(b-1)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N1 = 2005;
const int mod = 1e9 + 7;
int c[N1][N1];

// 直接用公式预处理
void init01()
{
    for (int i = 0; i < N1; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

// 用逆元的思维预处理——逆元用快速幂去做
const int N2 = 1e5 + 5;
int fact[N2], infact[N2];
int qmi(int a, int k, int m)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % m;
        a = (ll)a * a % m;
        k >>= 1;
    }
    return res;
}
void init02()
{
    fact[0] = fact[1] = 1;
    infact[0] = infact[1] = 1;
    for (int i = 2; i < N2; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

// 卢卡斯定理中要用到的质数
int p;
// 卢卡斯定理中要用到的快速幂
int qmioflucas(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}
// 卢卡斯定理中的函数C
int C(int a, int b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        res = (ll)res * j % p;
        res = (ll)res * qmioflucas(i, p - 2) % p;
    }
    return res;
}

// 卢卡斯定理
int lucas(ll a, ll b)
{
    if (a < p && b < p)
        return C(a, b);
    else
        return (ll)C(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main()
{
    // 公式处理
    // init01();
    //  int n;
    //  scanf("%d", &n);
    //  while (n--)
    //  {
    //      int a, b;
    //      scanf("%d%d", &a, &b);
    //      printf("%d\n", c[a][b]);
    //  }

    // 逆元处理
    // init02();
    // int n;
    // scanf("%d", &n);
    // while (n--)
    // {
    //     int a, b;
    //     scanf("%d%d", &a, &b);
    //     printf("%lld\n", (ll)fact[a] * infact[a - b] % mod * infact[b] % mod);
    // }

    // 卢卡斯定理处理
    int n;
    scanf("%d", &n);
    while (n--)
    {
        ll a, b;
        scanf("%lld%lld%d", &a, &b, &p);
        cout << lucas(a, b) << '\n';
    }
    return 0;
}