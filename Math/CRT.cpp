// 中国剩余定理
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    ll n;
    cin >> n;
    ll a1, m1;
    cin >> a1 >> m1;
    bool has_answer = true;
    for (int i = 1; i < n; i++)
    {
        ll a2, m2;
        cin >> a2 >> m2;

        ll k1, k2;
        ll d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d)
        { // 如果m2-m1不能被a1和a2的gcd整除
            has_answer = false;
            break;
        }

        k1 *= (m2 - m1) / d;
        ll t = a2 / d;
        k1 = (k1 % t + t) % t;
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if (has_answer)
        cout << (m1 % a1 + a1) % a1 << '\n';
    else
        puts("-1");
    return 0;
}