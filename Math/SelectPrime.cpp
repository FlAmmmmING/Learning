// 筛选出1~n内的素数,返回素数的个数
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> prime;
const int N = 1e6 + 10;
bool st[N]; // 判断是不是质数
// 埃氏筛法
// int get_prime01(int n)
// {
//     int res = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         if (!st[i])
//         {
//             prime.push_back(i);
//             res++;
//             for (int j = i + i; j <= n; j += i)
//                 st[j] = true;
//         }
//     }
//     return res;
// }

// 线性筛法——较快
int primes[N], cnt = 0; // 存放质数——即最小质因数,cnt是计数器
int get_prime02(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    return cnt;
}
int main()
{
    int n;

    cin >> n;
    // cout << get_prime01(n) << endl;//埃式筛法 O(n*log(logn))
    // for (int i = 0; i < prime.size(); i++)
    //     cout << prime[i] << " ";

    cout << get_prime02(n) << endl; // 线性筛法 O(n)
    for (int i = 0; i < cnt ; i++)
    {
        cout << primes[i] << " ";
    }
    return 0;
}
