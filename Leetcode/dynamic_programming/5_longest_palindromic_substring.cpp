# include <iostream>
# include <string>
using namespace std;

string longestPalindrome(string s) {
	if (s.size() <= 1)    
		return s;
	int mid = 0;
	int max_len = 0;
	int min_start = 0;
	for (mid = 0; mid < s.size();){   //mid表示回文字符最中间的部分，思想是固定中间值
		if (s.size() - mid <= max_len / 2)   //不会再有比max_len更长的子序列
			break;
		int start = mid;
		int end = mid;
		while (end < s.size() && s[end] == s[end + 1])   //若在字符串中间有回文序列，则无论多少个相同的元素，都不影响他是回文序列，且回文序列长度变长
			end++;
		mid = end + 1;   // 因为回文序列变长，所以中间值需要增加，而start不变，无论中间相同的元素是奇数还是偶数，都没有影响
		while (end < s.size() - 1 && start > 0 && s[start - 1] == s[end + 1]){
			start--;
			end++;
		}
		int len = end - start + 1;
		if (max_len < len){
			min_start = start;
			max_len = len;
		}
	}
	return s.substr(min_start, max_len);
}

int main(){
	string str;
	cin >> str;
	cout << longestPalindrome(str) << endl;
	return 0;
}