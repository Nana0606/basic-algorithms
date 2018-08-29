# include <iostream>
# include <vector>
# include <string>
using namespace std;

string findLongestWord(string s, vector<string>& d) {
	/**
	˼·������2���±꣬���s[i] == possi_str[j]�������±���������s�е��±�����j���±겻�䡣
	*/
	int len = d.size();
	string max_str = "";
	for (int p = 0; p < len; p++){
		string possi_str = d[p];
		int i = 0;
		int j = 0;
		for (i = 0, j = 0; i < s.length() && j < possi_str.length(); i++){  //ֻ��һ�Σ�������2��for����Ϊ2��for�������������������ڲ���Ȼ��ѭ������
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