// 高斯消元
// 对于列举每一列C
// 找到这一列系数的绝对值最大的数
// 将对应的这一行替换到最上面
// 将这一行的第一个数替换成1
// 将这一行下面所有行的第C列消成0
// 最后别忘了从下到上再把剩下非对角阵的元素消0

// 自己推一便即可
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const double esp = 1e-6; // 判断浮点数的误差，如果误差在esp范围之内，那就表示两数相等
// 高斯消元解线性方程组
int gauss01(double func[][N], int n)
{
    int row, column; // row是行，column是列
    for (row = 0, column = 0; column < n; column++)
    {
        int t = row; // 标记这一列绝对值最大的元素
        for (int i = row; i < n; i++)

            if (fabs(func[i][column]) > fabs(func[t][column]))
                t = i;

        if (fabs(func[t][column]) < esp)
            continue; // 最大的元素也是0，这个时候代表这一列都是0，结束本次循环

        // 将最大的元素对应的行放在最上面
        for (int i = column; i <= n; i++)
            swap(func[t][i], func[row][i]);

        // 将这一行的第一个数消为1
        for (int i = n; i >= column; i--)
            func[row][i] /= func[row][column];

        // 将这一行下面所有行的第C列消成0
        for (int i = row + 1; i < n; i++)
            if (fabs(func[i][column]) > esp)
                for (int j = n; j >= column; j--)
                    func[i][j] -= func[row][j] * func[i][column];
        row++;
    }
    // 最后别忘了从下到上再把剩下非对角阵的元素消0
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j <= n; j++)
            func[i][n] -= func[i][j] * func[j][n];

    if (row < n) // 判断无解或者是无穷解
    {
        for (int i = row; i < n; i++)
            if (fabs(func[i][n]) > esp)
                return 2; // 无解
        return 1;         // 无穷解
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    double func[N][N];
    for (int row = 0; row < n; row++)
        for (int column = 0; column <= n; column++)
            scanf("%lf", &func[row][column]);
    int d = gauss01(func, n);
    if (d == 1)
        puts("Infinite group solutions"); // 无穷解
    else if (d == 2)
        puts("No solution"); // 无解
    else
        for (int i = 0; i < n; i++)
            printf("%.2lf\n", func[i][n]);
    return 0;
}