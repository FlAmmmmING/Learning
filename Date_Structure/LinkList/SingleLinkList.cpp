#include <bits/stdc++.h>
using namespace std;

// 数组来模拟单链表
// e[i] 的值代表第i个结点的值
// ne[i] 的值代表第i个结点指向下一个结点的下标值
// 例子：nodei(v,next) v代表这个结点的值，next代表这个结点下一个结点的下标值
// head -> node0(3,1) -> node1(4,2) -> node2(7,3) -> -1(-1代表NULL)
// e[0] = 3, e[1] = 4, e[2] = 7
// ne[0] = 1, ne[1] = 2, ne[2] = 3, ne[3] = -1

const int N = 1e5 + 3;

// head代表头指针
// idx代表当前用到了哪一个点，相当于一个指针
int head, e[N], ne[N], idx;
void init()
{ // 初始化
    head = -1;
    idx = 0;
}

// 头插法
void add_to_head(int x)
{
    e[idx] = x;     // 给idx这个地方赋值
    ne[idx] = head; // 把head指向的next赋值给idx
    head = idx;     // head指向idx
    idx++;
}

// 在位置k后面插入数值为x的结点
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 单链表的删除操作
// 把下标为k的下一个点消掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int n;
    cin >> n;
    init();
    while (n--)
    {
        int k, x;
        char ch;
        cin >> ch;
        if (ch == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (ch == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
        else if (ch == 'I')
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    cout << '\n';
    return 0;
}