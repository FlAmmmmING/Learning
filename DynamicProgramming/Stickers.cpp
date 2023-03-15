//保留,不会




// 给定一个字符串str，给定一个字符串类型的数组arr，出现的字符都是小写英文
// arr每一个字符串，代表一张贴纸，你可以把单个字符剪开来使用，目的是为了拼出str来
// 返回需要至少多少张贴纸可以完成这个任务
// eg: str="babac", arr={"ba","c","abcd"}
// 至少需要两张贴纸"ba"和"abcd"，因为使用这两张贴纸，把每一个字符单独剪开，含有2个a、2个b、1个c。是可以拼出str的，所以返回2.

#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------

int process01(string stickers[], string target, int length);
string minus_str(string s1, string s2);
// 写出尝试
// length是stickers[]数组的长度
int minStickers1(string stickers[], string target, int length)
{
    return process01(stickers, target, length);
}

// 暴力递归
int process01(string stickers[], string target, int length)
{
    // 如果target没东西了，那就说明我需要0张卡
    if (target.length() == 0)
    {
        return 0;
    }
    // 最小张数来一个系统最大值
    int mi = 2147483647;
    for (int i = 0; i < length; i++)
    {
        string rest = minus_str(target, stickers[i]);
        if (rest.length() != target.length())
        {
            mi = mi < process01(stickers, rest, length) ? mi : process01(stickers, rest, length);
        }
    }
    return mi + (mi == 2147483647 ? 0 : 1);
}

string minus_str(string stickers, string target)
{
    string rest = target;
    for (int i = 0; i < stickers.length(); i++)
    {
        for (int j = 0; j < rest.length(); j++)
        {
            if (stickers[i] == rest[j])
            {
                rest[j] = '0';
                break;
            }
        }
    }
    string res;
    for (int i = 0; i < rest.length(); i++)
    {
        if (rest[i] != '0')
        {
            res = res + rest[i];
        }
    }
    return res;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    string stickers[3] = {"ba", "c", "abcd"};
    string target = "babac";
    cout << minStickers1(stickers, target, 3);
    return 0;
}