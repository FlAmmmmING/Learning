// 规定1和A对应，2和B对应，3和C对应
// 那个数字"111"就可以转化为"AAA"、"KA"、"AK"
// 给定一个只有数字字符组成的字符串str，返回有多少种转化结果

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
int process01(char str[], int i, int length);
// 初始代码
// 尝试
int number01(char str[], int length)
{
    return process01(str, 0, length);
}

// string从[0...i-1]的转化无需过问
// string从[i...]去转化，返回有多少转化方法
int process01(char str[], int i, int length)
{
    if (i == length)
    { // 找到了一种转化方法
        return 1;
    }
    // 如果i没有到最后
    if (str[i] == '0')
    { // 如果说str[i]=0，说明之前做过的决定错了，让i单独面对0字符
        return 0;
    }
    // str[i]位置不是0字符
    // 可能性1——一个字符单转
    int ways = process01(str, i + 1, length);
    if (i + 1 < length && (str[i] - '0') * 10 + str[i + 1] - '0' < 27)
    {
        ways += process01(str, i + 2, length);
    }
    return ways;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------

// 动态规划代码
int number02(char str[], int length)
{
    int *dp = new int[length + 1];
    for (int i = 0; i < length; i++)
    {
        dp[i] = 0;
    }
    //这一句对应的是上面暴力递归的str[i]=='0' return 0;
    dp[length] = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] != '0')
        {
            dp[i] = dp[i + 1];
            if (i + 1 < length && (str[i] - '0') * 10 + (str[i + 1] - '0') < 27)
            {
                dp[i] += dp[i + 2];
            }
        }
    }
    return dp[0];
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    char str[8] = "2132082";
    cout << number01(str, 7) << endl;
    cout << number02(str, 7) << endl;
    return 0;
}