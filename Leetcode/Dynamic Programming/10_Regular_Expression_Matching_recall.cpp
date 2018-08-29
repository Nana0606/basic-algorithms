# include <iostream>
# include <string>
using namespace std;

/**
使用回溯方法解决，参考https://blog.csdn.net/hk2291976/article/details/51165010
注意注意: 这个case是有问题的：
		string s = "aaa";
		string p = "ab*a*c*a";
		因为在从后向前遍历的过程中，a*把所有的a都匹配完了，导致最开始的a没有匹配选择。
*/

static const int FRONT = -1;    //防止数组越界，停止标识
bool myMatch(string s, int i, string p, int j);    //声明函数

bool isMatch(string s, string p){
	return myMatch(s, s.length() - 1, p, p.length() - 1);
}

bool myMatch(string s, int i, string p, int j){
	// Step1: 若满足终止条件则终止
	if (j == FRONT){
		if (i == FRONT)
			return true;
		else
			return false;
	}
	//若p[j] == '*'，则前面的字符可以出现0次或多次
	if (p[j] == '*'){
		if (i > FRONT && (p[j - 1] == s[i] || p[j - 1] == '.'))
			return myMatch(s, i - 1, p, j);
		else
			return myMatch(s, i, p, j - 2);
	}
	//若p[j] == '.'，则s中可以是任意字符
	if (p[j] == '.'){
		return myMatch(s, i - 1, p, j - 1);
	}
	//若p[j] != '*' && p[j] != '.'，则说明是正常的字符，只需判断对应字符是否相等即可
	if (p[j] != '*' && p[j] != '.'){
		if (s[i] == p[j]){
			return myMatch(s, i - 1, p, j - 1);
		}
		else
			return false;
	}
}


int main(){
	string s = "aaa";
	string p = "ab*a*c*a";
	bool result = isMatch(s, p);
	cout << result << endl;
	return 0;
}