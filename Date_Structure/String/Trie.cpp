#include <bits/stdc++.h>
using namespace std;

// 字典树，前缀树
// Trie树：高效地存储和查找字符串集合的数据结构

// 维护一个字符串集合，支持两种操作：
// I x 向集合中插入一个字符串 x；
// Q x 询问一个字符串在集合中出现了多少次。
// 共有 N 个操作，所有输入的字符串总长度不超过 105，字符串仅包含小写英文字母

const int N = 1e5 + 3;
int son[N][26], cnt[N], idx = 0; // 下标是0的点，即是空结点，又是头结点
char str[N];
// Trie树的插入操作
void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (son[p][u] == 0) // 代表这里没有路
            son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++; // 记录一下这个字符串的末尾，代表这里有一个字符串
}

// Trie树的查询操作
int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (son[p][u] == 0) // 代表这里不通
            return 0;
        p = son[p][u];
    }
    return cnt[p]; // 返回以p结尾的单词的数量
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I')
            insert(str);
        else
            cout << query(str) << '\n';
    }
    return 0;
}