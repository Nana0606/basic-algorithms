# include <iostream>
# include <string>
# include <map>
# include <unordered_map>
using namespace std;

// AC, 代码冗余。主要为了处理4,9,40,90,400,900等情况导致的代码冗余。
/*
int romanToInt(string s) {
	map<char, int> m;
	m.insert(pair<char, int>('I', 1));
	m.insert(pair<char, int>('V', 5));
	m.insert(pair<char, int>('X', 10));
	m.insert(pair<char, int>('L', 50));
	m.insert(pair<char, int>('C', 100));
	m.insert(pair<char, int>('D', 500));
	m.insert(pair<char, int>('M', 1000));
	int res = 0;
	for (int i = 0; i < int(s.length()); i++){
		if (s[i] == 'I' && i < int(s.length()) - 1){
			if (s[i+1] == 'V') {
				res += 4;
				i++;
				continue;
			}
			else if (s[i+1] == 'X'){
				res += 9;
				i++;
				continue;
			}
			else{
				res += m[s[i]];
			}
		}
		else if (s[i] == 'X' && i < int(s.length()) - 1){
			if (s[i+1] == 'L') {
				res += 40;
				i++;
				continue;
			}
			else if (s[i+1] == 'C'){
				res += 90;
				i++;
				continue;
			}
			else{
				res += m[s[i]];
			}
		}
		else if (s[i] == 'C' && i < int(s.length()) - 1){
			if (s[i+1] == 'D') {
				res += 400;
				i++;
				continue;
			}
			else if (s[i+1] == 'M'){
				res += 900;
				i++;
				continue;
			}
			else{
				res += m[s[i]];
			}
		}
		else{
			res += m[s[i]];
		}
	}
	return res;
}
*/


// 方法二：
int romanToInt(string s){
	unordered_map<char, int> temp = {
		{ 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10},
		{ 'L', 50},
		{ 'C', 100},
		{ 'D', 500},
		{ 'M', 1000 }
	};
	int sum = temp[s[s.length()-1]];  // 最后一个元素，首先加入
	for (int i = int(s.length()) - 2; i >= 0; i--){   //这点比较cool，要从中找点技巧
		if (temp[s[i]] < temp[s[i + 1]]){
			sum -= temp[s[i]];
		}
		else{
			sum += temp[s[i]];
		}
	}
	return sum;
}


int main(){
	string s = "MCMXCIV";
	int res = romanToInt(s);
	cout << res << endl;;
	return 0;
}