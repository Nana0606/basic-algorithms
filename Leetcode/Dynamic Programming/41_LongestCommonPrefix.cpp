#include <iostream>
#include <vector>
#include<string>
using namespace std;

// 这一题很快就做出来了，转化成二个元素的公共前缀问题

string twoCommonString(string str1, string str2){
    int index = str1.length() < str2.length() ? str1.length() : str2.length();
    int i = 0;
    for(i = 0; i < index; ++i){
        if(str1[i] != str2[i]){
            return str1.substr(0, i);
            break;
        }
    }
    if (i == 0)
        return "";
    return str1.substr(0, i);
}

string longestCommonPrefix(vector<string>& strs) {
    int len = strs.size();
    if (len == 0)
        return "";
    else if(len == 1)
        return strs[0];
    else{
        string first = strs[0];
        for ( int i = 1; i < strs.size(); ++i){
            first = twoCommonString(first, strs[i]);
        }
        return first;
    }
}

int main()
{
    string words[] = {"abcc", "abuyyc", "ab"};
    vector<string> strs(words, words+sizeof(words)/sizeof(string));
    string result = longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}
