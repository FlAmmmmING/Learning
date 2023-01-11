// 基于荷兰问题的快速排序进阶
// 荷兰国旗问题请鉴"DutchFlag.cpp"
#include <iostream>
using namespace std;
// 随机数生成
#define random(a, b) rand() % (b - a) + a

// partition的功能是返回荷兰国旗中间的左边界和右边界
int *partition(int *arr, int left, int right)
{
    int L = left;
    int R = right;
    int i = left; // 遍历用的
    while (i <= R)
    {
        if (arr[i] < arr[0])
        {
            swap(arr[i++], arr[L++]);
        }
        else if (arr[i] == arr[0])
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[R--]);
        }
    }
    return new int[2]{L, R};
}

void QuickSorting(int *arr, int left, int right)
{
    if (left < right)
    {
        // 将数组中的随机数存放入哨兵处
        arr[0] = arr[random(left, right)];
        // midarr数组是荷兰国旗中间等于arr[0]区域的左边界的下标和右边界的下标组成的数组
        int *midarr = partition(arr, left, right);
        QuickSorting(arr, midarr[0] + 1, right);//划分值1
        QuickSorting(arr, left, midarr[1] - 1);//划分值2
    }
}

int main()
{
    cout << "please input the length:>";
    int n;
    cin >> n;
    cout << "please input the data:>";
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    // 这里多开辟了一个空间，让arr[0]作为哨兵
    arr[0] = -1;
    // 以下是基于荷兰国旗问题的快速排序的实现
    QuickSorting(arr, 1, n);
    cout << "QuickSorting:>";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}