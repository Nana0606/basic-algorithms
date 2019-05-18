#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

# ������ĸ���ִ��������ֵ����Сֵ֮��
# ����ע�⣬���ܽ�minV��ʼ��Ϊһ������100��ֵ��Ȼ����ÿ��ѭ���ڱȽϣ���Ϊ���ܳ��֡�aaa������aaaa������aaabbb����Щ�������
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

# �ж�һ�������Ƿ�Ϊ����
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
