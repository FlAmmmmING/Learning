#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7; // 数据可能过大，所以取模

// 试除法求一个数的所有约数
void divisors01()
{
    vector<int> divs;
    int n;
    cin >> n;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            if (i != n / i)
                divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    for (int i = 0; i < divs.size(); i++)
    {
        cout << divs[i] << " ";
    }
    cout << endl;
}

// 约数个数
// 给定 n 个正整数 ai ，请你输出这些数的乘积的约数个数，答案对 109+7 取模。
// 数论：对于一个数num，num可以被分解为: p1^a1 * p2^a2 * ... pk^ak , 则约数个数为: (a1+1)*(a2+1)*...(ak+1)

ll divisors02()
{
    int t;
    cin >> t;
    unordered_map<int, int> hash; // 哈希表
    while (t--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
            while (x % i == 0)
            {
                x /= i;
                hash[i]++;
            }
        if (x > 1)
        {
            hash[x]++;
        }
    }
    ll res = 1;
    for (auto p : hash)
    {
        res = res * (p.second + 1) % mod;
    }
    return res;
}

// 约数之和
// 给定 n 个正整数 ai ，请你输出这些数的乘积的约数之和，答案对 109+7 取模。
// 数论: 对于一个数num，num可以被分解为: p1^a1 * p2^a2 * ... pk^ak , 则约数之和为:
// (p1^0+p1^1+...+p1^a1)*(p2^0+p2^1+...+p2^a2)*...(pk^0+pk^1+...+pk^ak)
ll divisors03()
{
    int t;
    cin >> t;
    unordered_map<int, int> hash; // 哈希表
    while (t--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                hash[i]++;
            }
        }
        if (x > 1)
            hash[x]++;
    }
    ll res = 1;
    for (auto pr : hash)
    {
        int p = pr.first;
        int a = pr.second;
        ll t = 1;
        while (a--)
        {
            t = (p * t + 1) % mod; // 秦昭九算法 f(1) = 1, f(n) = f(n-1)*p + 1;
        }
        res = res * t % mod;
    }
    return res;
}

// 欧几里得——辗转相除法求gcd
int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    // 试除法求一个数的所有约数
    //  int t;
    //  cin >> t;
    //  while (t--)
    //  {
    //      divisors01();
    //  }

    // 约数个数
    // cout << divisors02() << endl;

    // 约数之和
    // cout << divisors03() << endl;

    // 欧几里得——辗转相除法求gcd
    // int x, y;
    // cin >> x >> y;
    // cout << gcd(x, y) << endl;

    return 0;
}
