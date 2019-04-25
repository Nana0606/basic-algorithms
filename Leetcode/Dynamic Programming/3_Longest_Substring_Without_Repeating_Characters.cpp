# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

/**
解题思路：使用一个vector，将其初始值全部记为-1，vector[i]用来表示s[i]在之前没有出现过

dict[s[i]] > start比较dict[s[i]]和start的大小关系，因为dict[s[i]]是记录的index值，所以若大于start，说明之前有出现过这个字符，此时更新start
最大值从上一轮的最大值和(i-start)中选择

相当于start是记录某个字符上一轮出现的位置，i-start就是求当前值到出现重复的值之间的间隔
*/

int lengthOfLongestSubstring(string s){
	vector<int> dict(256, -1);   // 256个-1，ascii大小为256
	int maxLen = 0, start = -1;
	for (int i = 0; i < (int)s.length(); ++i){
		if (dict[s[i]] > start){    // 之前有出现过这个字符
			start = dict[s[i]];
		}
		dict[s[i]] = i;   //将dict[s[i]] 赋值当前的位置，便于i-start
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