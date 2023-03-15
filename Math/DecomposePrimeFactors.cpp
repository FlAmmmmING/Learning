// 分解质因数——试除法
// 给定 n 个正整数 ai ，将每个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数

#include <iostream>
#include <algorithm>
using namespace std;

void factors()
{
    int x;
    scanf("%d", &x);
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int sum = 0;
            while (x % i == 0)
            {
                sum++;
                x /= i;
            }
            printf("%d %d\n", i, sum);
        }
    }
    if (x > 1)
        printf("%d %d", x, 1);
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        factors();
    }
    return 0;
}