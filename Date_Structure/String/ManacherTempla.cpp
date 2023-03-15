// 求最长回文子串

#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char Ma[N * 2], s[N];
int Mp[N * 2]; // Mp[i] 代表以当前这个点为中心可以获得的回文子串的最大半径

void Manacher(char s[], int len)
{
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';

    for (int i = 0; i < len; i++)
    {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;

    // 以上代码都是初始化
    // 以下代码是马拉车代码的核心

    int mx = 0, id = 0;
    for (int i = 0; i < l; i++)
    {
        Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
        while (Ma[i + Mp[i]] == Ma[i - Mp[i]])
            Mp[i]++;
        if (i + Mp[i] > mx)
        {
            mx = i + Mp[i];
            id = i;
        }
    }
}

int main()
{
    cin >> s;
    int len = strlen(s);
    Manacher(s, len);
    for (int i = 1; i <= 2 * len + 1; i++) // 输出Ma
        cout << Ma[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= 2 * len + 1; i++) // 输出Mp
        cout << Mp[i] << ' ';
    cout << '\n';
    int res = 0;
    for (int i = 0; i < 2 * (len + 1); i++)
        res = max(res, Mp[i] - 1);
    cout << res << '\n';
    return 0;
}