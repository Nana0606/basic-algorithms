#include <iostream>

using namespace std;

//�ж�str1�Ƿ���str2���Ӵ�
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
    string temp = ""; //temp���ڼ�¼�����Ӵ�
    int tempLen = 0; //tempLen���ڼ�¼�����Ӵ��ĳ���
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
                if (result == 1)   //˵�����Ӵ�
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
        return "û�й����Ӵ�";
    return temp;
}

int main()
{
    cout << commonSubstring("dcdf4", "cdf45") << endl;
    return 0;
}
