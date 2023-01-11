// 求小和问题
//[1,3,4,2,5] 1的左边比1小的数没有，3的左边比3小的数有1……以此类推
// 则这个数组的小和为: 1 + 1 + 3 + 1 + 1 + 1 + 3 + 4 + 2 = 16

#include <iostream>
using namespace std;

int merge(int *arr, int left, int mid, int right)
{
    int *help = new int[right - left + 1]; // 开辟一个辅助空间
    int i = 0;//help数组的指针
    //p1和p2是两个指针用于归并排序
    int p1 = left;
    int p2 = mid + 1;
    int res = 0; // 这个是小和的总和
    while (p1 <= mid && p2 <= right)
    {
        res += arr[p1] < arr[p2] ? (right - p2 + 1) * arr[p1] : 0;
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    //将剩下的数据直接赋值到help里面
    while (p1 <= mid)
    {
        help[i++] = arr[p1++];
    }
    while (p2 <= right)
    {
        help[i++] = arr[p2++];
    }
    for (int i = 0; i < right - left + 1; i++)
        arr[left + i] = help[i];
    delete help;
    help = NULL;
    return res;
}

// process函数用用来归并递归
int process(int *arr, int left, int right)
{
    if (left == right)
        return 0;
    int mid = left + (right - left) / 2;
    return process(arr, left, mid) + process(arr, mid + 1, right) + merge(arr, left, mid, right); // 核心递归思路
}

// 求小和的主函数
int smallSum(int *arr, int length)
{
    if (arr == NULL || length < 2)
        return 0;
    else
        return process(arr, 0, length - 1);
}

int main()
{
    int n;
    cout << "please input the length:>";
    cin >> n;
    cout << "please input the data:>";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 求小和问题这里利用了归并排序的思想
    int res = smallSum(arr, n);
    cout << "get_smallSum:>" << res << endl;
    return 0;
}
