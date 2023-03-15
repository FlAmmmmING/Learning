// 给定 n 个正整数 ai ，请你求出每个数的欧拉函数
// 对于一个数：Num = p1^a1 * p2^a2 * ... * pk^ak
// 则根据欧拉函数，可以求得这个数Num与前1~Num-1中有多少个数与Num互质，这个就叫欧拉函数
//  f(Num)=Num * (1-1/p1) * (1-1/p2) * ... * (1-1/pk);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 经典方法求欧拉函数
void euler01()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int res = x;
        for (int i = 2; i <= x / i; i++)
            if (x % i == 0)
            {
                res = res / i * (i - 1);
                while (x % i == 0)
                    x /= i;
            }
        if (x > 1)
            res = res / x * (x - 1);
        cout << res << endl;
    }
}

// 欧拉函数加上线性筛法
// 给定一个正整数 n ，求 1∼n 中每个数的欧拉函数之和。
const int N = 1e6 + 10;
bool st[N];           // 初始为false
ll phi[N], primes[N]; // phi存储的是第i个欧拉函数的值,primes[N]记录的是素数
int cnt = 0;
ll euler02()
{
    int n;
    cin >> n;
    phi[1] = 1; // 1之前只有一个数和它互素
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1; // i已经是素数，那之前和i互素的数一共有i-1个
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) // 如果i能被primes[j]这个素数整除
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            else // 如果不能被整除
            {
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += phi[i];
    }
    return res;
}

int main()
{
    // euler01();
    cout << euler02() << endl;
    return 0;
}

// 补充
// 欧拉定理:如果a与n互质，则有 a ^ f(n) ≡ 1 (mod n) ,其中，f(n)是欧拉函数
