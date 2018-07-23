#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

# 计算字母出现次数的最大值和最小值之差
# 这里注意，不能将minV初始化为一个大于100的值，然后在每个循环内比较，因为可能出现“aaa”、“aaaa”、“aaabbb”这些特殊情况
int isLucky(string word)
{
    int p[26] = {0};
    int maxV = 0, minV = 0;
    for (int i = 0; i < word.length(); ++i)
    {
        p[word[i]-'a'] += 1;
    }
    sort(p, p+26);
    maxV = p[25];
    for (int i = 0; i < 26; i++)
    {
        if(p[i]!=0 && i!=25)
        {
            minV = p[i];
            break;
        }
    }
    return maxV - minV;
}

# 判断一个整数是否为质数
bool isPrime(int a)
{
    for (int i = 2; i <= sqrt(a); ++i)
        if( a % i == 0) return false;
        return true;
}

int main()
{
    int N;
    cin.sync_with_stdio(false);
    cin >> N;
    while(N--)
    {
        string word;
        cin >> word;
        int value = isLucky(word);
        if( value == 0 || value == 1)
        {
            cout << "No Answer" << endl;
            cout << "0" << endl;
        }
        else
        {
         if(isPrime(value) == true)
         {
             cout << "Lucky Word" << endl;
             cout << value << endl;
         }
         else
         {
             cout << "No Answer" << endl;
             cout << "0" << endl;
         }
        }
    }
    return 0;
}
