#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3, M = 1e6 + 3;
char p[N], s[M];
int ne[N];
int n, m;
// KMP 算法
// next 数组只依赖于子字符串
int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    // 求next数组的过程
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1; i <= n; i++)
        cout << ne[i] << ' '; // next数组展示
    cout << "\n--------------------------------------\n";

    // 开始匹配字符串
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            cout << i - n << ' ';
            j = ne[j];
        }
    }

    return 0;
}