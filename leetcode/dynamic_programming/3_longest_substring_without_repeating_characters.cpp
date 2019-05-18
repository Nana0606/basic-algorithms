# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

/**
����˼·��ʹ��һ��vector�������ʼֵȫ����Ϊ-1��vector[i]������ʾs[i]��֮ǰû�г��ֹ�

dict[s[i]] > start�Ƚ�dict[s[i]]��start�Ĵ�С��ϵ����Ϊdict[s[i]]�Ǽ�¼��indexֵ������������start��˵��֮ǰ�г��ֹ�����ַ�����ʱ����start
���ֵ����һ�ֵ����ֵ��(i-start)��ѡ��

�൱��start�Ǽ�¼ĳ���ַ���һ�ֳ��ֵ�λ�ã�i-start������ǰֵ�������ظ���ֵ֮��ļ��
*/

int lengthOfLongestSubstring(string s){
	vector<int> dict(256, -1);   // 256��-1��ascii��СΪ256
	int maxLen = 0, start = -1;
	for (int i = 0; i < (int)s.length(); ++i){
		if (dict[s[i]] > start){    // ֮ǰ�г��ֹ�����ַ�
			start = dict[s[i]];
		}
		dict[s[i]] = i;   //��dict[s[i]] ��ֵ��ǰ��λ�ã�����i-start
		maxLen = max(maxLen, i - start);
		if (((int)s.length() - start - 1) <= maxLen)
			break;
	}
	return maxLen;
}

int main(){
	string str;
	while (cin >> str){
		int result = lengthOfLongestSubstring(str);
		cout << result << endl;
	}
}