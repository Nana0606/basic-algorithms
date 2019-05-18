# include <iostream>
# include <unordered_map>
# include <string>
using namespace std;


//保证2个字符串的每一个元素个数相同即可
bool isAnagram(string s, string t) {
	if (s.length() != t.length()) return false;
	unordered_map<char, int> counts;
	for (int i = 0; i < s.length(); i++){
		counts[s[i]] ++;
		counts[t[i]] --;
	}
	for (auto count : counts){
		if (count.second != 0) return false;
	}
	return true;
}

int main(){
	string s = "rat", t = "cat";
	bool result = isAnagram(s, t);
	cout << result << endl;
	return 0;
}

