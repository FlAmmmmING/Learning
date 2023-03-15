// 扩展 KMP 算法    板子
// next[i]: x[i .. m - 1] 与 x[0 ... m - 1] 的最长公共前缀
// extend[i]: y[i ... n - 1] 与 x[0 ... m - 1] 的最长公共前缀

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int ne[N], extend[N];            // next 数组 与 extend 数组
char s1[N], s2[N];               // s1 是子串 , s2 是主串
void pre_ekmp(char str[], int m) // 预处理出子串的next数组
{
    ne[0] = m; // next 数组的第一个元素就是子串的长度, 因为子串和自己的前缀和一定是自己的长度
    int j = 0;
    while (j + 1 < m && str[j] == str[j + 1])
        j++; // 用于预处理出 next[1]
    ne[1] = j;
    int pos = 1; // 从 1 开始的 idx
    for (int i = 2; i < m; i++)
    {
        int p = ne[pos] + pos - 1;
        int l = ne[i - pos];
        if (i + l < p + 1)
            ne[i] = l;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < m && str[i + j] == str[j])
                j++;
            ne[i] = j;
            pos = i;
        }
    }
}

void extend_KMP(char s1[], int m, char s2[], int n) // 处理出extend数组
{
    pre_ekmp(s1, m);
    int j = 0;
    while (j < n && j < m && s1[j] == s2[j])
        j++;
    extend[0] = j; // 先处理出extend[0]

    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        int p = extend[pos] + pos - 1;
        int l = ne[i - pos];
        if (i + l < p + 1)
            extend[i] = l;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < n && j < m && s2[i + j] == s1[j])
                j++;
            extend[i] = j;
            pos = i;
        }
    }
}

int main()
{
    cin >> s2 >> s1; // s2 主串, s1 子串
    int m = strlen(s1);
    int n = strlen(s2);
    extend_KMP(s1, m, s2, n);
    for (int i = 0; i < m; i++) // 子串next数组的输出
        cout << ne[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) // 主串extend数组的输出
        cout << extend[i] << ' ';
    cout << '\n';
    return 0;
}