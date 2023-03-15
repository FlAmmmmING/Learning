// 扩展欧几里得算法——扩展辗转相除法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b) // b == 0 递归终止条件
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    // 扩展欧几里得算法
    // 给定 n 对正整数 ai,bi，对于每对数，求出一组 xi,yi，使其满足 ai×xi+bi×yi=gcd(ai,bi)。
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }

    // 扩展欧几里得算法应用——求解线性同余方程
    // 给定 n 组数据 ai,bi,mi，对于每组数求出一个 xi，使其满足 ai×xi≡bi(mod mi)，如果无解则输出 impossible。
    // int n;
    // scanf("%d", &n);
    // while (n--)
    // {
    //     int a, b, m;
    //     scanf("%d%d%d", &a, &b, &m);
    //     int x, y;
    //     int d = exgcd(a, m, x, y);
    //     if (b % d)
    //         printf("impossible\n");
    //     else
    //         printf("%d\n", (ll)x * (b / d) % m);
    // }
    // return 0;
}