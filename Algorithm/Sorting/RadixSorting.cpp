// 运用词频表来实现基数排序
#include <iostream>
using namespace std;

// 这个函数的作用是判断这个数组中最大元素的位数
int arrdigit(int *arr, int length)
{
    int *help = new int[length];
    for (int i = 0; i < length; i++)
        help[i] = arr[i];
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        int temp = 0;
        while (help[i])
        {
            temp++;
            help[i] /= 10;
        }
        res = res >= temp ? res : temp;
    }
    delete help;
    help = NULL;
    return res;
}

// 这个函数是用来返回一个数字中第d位的数字
int getdigit(int num, int d)
{
    while (d > 1)
    {
        num /= 10;
        d--;
    }
    return num % 10;
}

// 基数排序的函数代码，这里arr是数组，left是数组的最左边，right是数组的最右边，digit是数组的位数
void RadixSorting(int *arr, int left, int right, int digit)
{
    const int radix = 10;
    int i = 0, j = 0;
    int *bucket = new int[right - left + 1];
    for (int d = 1; d <= digit; d++)
    { // 有多少位就进出几次
        // 一共就只需要开一个空间为10的词频表，因为每一个数都是由[0~9]的数字组成的
        // count[0] 当前(d位)是0的数字有多少个
        // count[1] 当前(d位)是1的数字有多少个
        // ………………
        int *count = new int[radix];    // count[0...9]
        for (int i = 0; i < radix; i++) // 将词频表变成0
            count[i] = 0;
        for (int i = left; i <= right; i++)
        {
            j = getdigit(arr[i], d);
            count[j]++;
        }
        // 将词频表变成前缀和
        for (int i = 1; i < radix; i++)
        {
            count[i] += count[i - 1];
        }
        // 从右边往左边开始基数排序
        for (int i = right; i >= left; i--)
        {
            j = getdigit(arr[i], d);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }
        for (int i = left, j = 0; i <= right; i++, j++)
            arr[i] = bucket[j];
    }
}

int main()
{
    cout << "please input the length:>";
    int n;
    cin >> n;
    cout << "please intput the data:>";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 以下是基数排序实现的函数
    int digit = arrdigit(arr, n);
    RadixSorting(arr, 0, n - 1, digit);
    cout << "RadixSorting:>";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}