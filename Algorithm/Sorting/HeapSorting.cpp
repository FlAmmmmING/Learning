// 进阶的堆排序问题——大根堆
#include <iostream>
#include <algorithm>
using namespace std;

// 这个函数数用来判断数组arr中下标索引是index数据是否大于它的父结点，如果大于，那就交换两个数据
void HeapInserting(int *arr, int index)
{
    while (arr[index] > arr[(index - 1) / 2])
    {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// 堆化函数
void Heapify(int *arr, int index, int heapSize)
{
    int left = index * 2 + 1; // 左孩子的下标
    while (left < heapSize)
    { // 下方还有左孩子的时候
        // 两个孩子中，谁的值大，把下标给largest
        int largest = (left + 1 < heapSize) && arr[left + 1] > arr[left] ? left + 1 : left; // 如果有右孩子，那就开始比较，反之则直接将left的值给largest
        // 父亲结点和孩子之间，谁的值更大，就把下标赋值给largest
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index) // 如果说largest就是index，就说明本身就是大根堆了
            break;
        swap(arr[largest], arr[index]);
        index = largest;
        left = index * 2 + 1;
    }
}

// 堆排序的主函数
void HeapSort(int *arr, int length)
{
    if (arr == NULL || length < 2)
        return; // 这个时候不需要排序
    for (int i = 1; i < length; i++)
        HeapInserting(arr, i);
    int heapSize = length;
    swap(arr[0], arr[--heapSize]);
    while (heapSize > 0)
    {
        Heapify(arr, 0, heapSize);
        swap(arr[0], arr[--heapSize]);
    }
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
    // 堆排序函数
    HeapSort(arr, n);
    cout << "HeapSorting:>";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}