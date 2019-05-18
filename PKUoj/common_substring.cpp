#include <iostream>

using namespace std;

//判断str1是否是str2的子串
int findStr(string str1, string str2)
{
    string::size_type idx;
    idx = str2.find(str1);
    if(idx == string::npos)
    {
        return 0;
    }
    else return 1;
}


string commonSubstring(string str1, string str2)
{
    string temp = ""; //temp用于记录公共子串
    int tempLen = 0; //tempLen用于记录公共子串的长度
    for(int i = 0; i < str1.length(); i++)
    {
        //cout << "i= " << i << endl;
        for (int j = 1; j <= str1.length(); j++)
        {
            int count = j - i;
            string subStr = str1.substr(i, count);
            cout<<"i = " << i << " j = " << j << "subStr: " << subStr <<endl;
            if(subStr.length() > 0)
            {
                int result = findStr(subStr, str2);
                if (result == 1)   //说明有子串
                {
                    if(tempLen < subStr.length())
                    {
                        temp = subStr;
                        tempLen = subStr.length();
                    }
                }
            }

        }
    }
    if(temp.length() == 0 )
        return "没有公共子串";
    return temp;
}

int main()
{
    cout << commonSubstring("dcdf4", "cdf45") << endl;
    return 0;
}
