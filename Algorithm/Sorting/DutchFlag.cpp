// 荷兰国旗问题
// 给定一个数组arr和一个数x，要求将数组中小于x的数排到最左边，大于x数到最右边，等于x的数放中间
// eg: arr=[4,5,2,6,7,3,1,9,5] , x = 5 最后 -> arr=[4,2,3,1,5,5,6,7,9]
#include <iostream>
using namespace std;

void DutchFlag(int *&arr, int left, int right, int index)
{
    int i = left;      // 指针i用于遍历
    while (i <= right) // 当i==right的时候，就代表递归结束，荷兰国旗问题完成
    {
        // 三种情况讨论
        if (arr[i] < index)
            swap(arr[i++], arr[left++]);
        else if (arr[i] == index)
            i++;
        else
            swap(arr[i], arr[right--]);
    }
}

int main()
{
    cout << "please input the length;>";
    int n;
    cin >> n;
    cout << "please input the data:>";
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "please input the X:>";
    int index;
    cin >> index;

    // 以下是荷兰国旗问题的函数
    DutchFlag(arr, 0, n - 1, index);
    cout << "DutchFlag:>";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}