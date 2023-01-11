// 找出数组中逆序对的个数
// eg:[4,2,3,1]所有的逆序对有：<4,2> <4,3> <4,1> <2,1> <3,1> ,一共有五个逆序对

// 仍然用归并的方法进行逆序对的选取，详情请鉴"getSmallSum.cpp"文件
#include <iostream>
using namespace std;

int merge(int *arr, int left, int mid, int right)
{
    int *help = new int[right - left + 1];
    int i = 0; // help数组的指针
    int p1 = left;
    int p2 = mid + 1;
    int res = 0; // 计算此次归并排序中的逆序对数量
    while (p1 <= mid && p2 <= right)
    {
        res += arr[p1] > arr[p2] ? (p2 - mid) : 0;
        help[i++] = arr[p1] > arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid)
        help[i++] = arr[p1++];
    while (p2 <= right)
        help[i++] = arr[p2++];
    for (int i = 0; i < (right - left + 1); i++)
        arr[left + i] = help[i];
    delete help;
    help = NULL;
    return res;
}

int process(int *arr, int left, int right)
{
    if (left == right)
        return 0;
    int mid = left + (right - left) / 2;
    //递归核心
    return process(arr, left, mid) + process(arr, mid + 1, right) + merge(arr, left, mid, right);
}

int getReverseOrderPairs(int *arr, int length)
{
    if (arr == NULL || length < 2)
        return 0;
    else
        return process(arr, 0, length - 1);
}

int main()
{
    cout << "please input the length:>";
    int n;
    cin >> n;
    cout << "please input the data:>";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 接下来开始进行逆序对计数，这里用到的仍然是归并排序
    int res = getReverseOrderPairs(arr, n);
    cout << "ReverseOrderPairs:>" << res << endl;
    return 0;
}