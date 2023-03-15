// 容斥原理
// 容斥原理的时间复杂度是 O(2^n)
// 定一个整数 n 和 m 个不同的质数 p1,p2,…,pm。
// 请你求出 1∼n 中能被 p1,p2,…,pm 中的至少一个数整除的整数有多少个。

// 用位运算来枚举集合
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
ll p[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i];
    int res = 0;
    for (int i = 1; i < 1 << m; i++)
    {
        int t = 1, cnt = 0;
        for (int j = 0; j < m; j++)
            if (i >> j & 1)
            {
                cnt++;
                if ((ll)t * p[j] > n)
                {
                    t = 0;
                    break;
                }
                t *= p[j];
            }
        if (t)
        {
            if (cnt % 2)
                res += n / t;
            else
                res -= n / t;
        }
    }
    cout << res << '\n';
    return 0;
}