#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<char> transform(string str)
{
    vector<char> vec;
    for (int i = 0; i < str.length(); i++)
    {
        vec.push_back(str[i]);
    }
    return vec;
}

int sortNumber (string str)
{
    vector<char> vec = transform(str);
    int count = 0;
    for ( int i = 0; i < vec.size(); i++)
    {
        char current = vec[i];
        for ( int j = i; j < vec.size(); j++)
        {
            if(current > vec[j]) count++;
        }
    }
    return count;
}

int cmp(const pair<int, int> &x, const pair<int, int> &y)
{
    return x.second < y.second;
}

void sortMapByValue(map<int, int> &t_map, vector<pair<int, int> > &t_vec)
{
    for(map<int,int>::iterator curr = t_map.begin(); curr != t_map.end(); curr++)
        t_vec.push_back(make_pair(curr -> first, curr -> second));
    sort(t_vec.begin(), t_vec.end(), cmp);
}

int main()
{
    int m,n; //m表示字符串的长度，n表示字符串的个数。
    cin >> m >> n;
    string * strs = new string[n];
    std::map<int, int> sortNums;
    //输入n个m长的字符串

    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
        sortNums[i] = sortNumber(strs[i]);
        //cout << sortNums[i] << " ";
    }

    vector<pair<int, int> > tVector;
    sortMapByValue(sortNums, tVector);
    for (int i = 0; i < tVector.size(); i++)
    {
        cout << strs[tVector[i].first] << endl;
    }
    delete[] strs;
    return 0;
}
