# include <iostream>
# include <vector>
# include <string>
using namespace std;

string findLongestWord(string s, vector<string>& d) {
	/**
	思路：设置2个下标，如果s[i] == possi_str[j]，则往下遍历，否则s中的下标增大，j中下标不变。
	*/
	int len = d.size();
	string max_str = "";
	for (int p = 0; p < len; p++){
		string possi_str = d[p];
		int i = 0;
		int j = 0;
		for (i = 0, j = 0; i < s.length() && j < possi_str.length(); i++){  //只需一次，不能用2重for，因为2重for，外层满足结束条件，内层仍然会循环遍历
			if (s[i] == possi_str[j]){
				j++;
			}
		}
		if (j == possi_str.length() && (max_str.length() < possi_str.length() || (max_str.length() == possi_str.length() && max_str > possi_str))){
			max_str = possi_str;
		}
	}
	return max_str;
}

int main(){
	string s = "bab";
	vector<string> d = { "ba", "ab", "a", "b"};
	string result = findLongestWord(s, d);
	cout << result << endl;
	return 0;
}