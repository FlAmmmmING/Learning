// 快速幂
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 给定 n 组 ai,bi,pi，对于每组数据，求出 ai^bi mod pi 的值。
int qmi01(int a, int k, int p)
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

int main()
{
    // 快速幂代码
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);
        printf("%d\n", qmi01(a, k, p));
    }
    return 0;
}