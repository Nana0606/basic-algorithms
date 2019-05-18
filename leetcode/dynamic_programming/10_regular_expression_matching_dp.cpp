# include <iostream>
# include <string>
using namespace std;

/**
Accepted
使用动态规划，动态规划还是需要仔细考虑的，主要考虑以下
	1、动态变换方程。
	2、初始化的数组。
参考文章: https://blog.csdn.net/hk2291976/article/details/51165010

主要思路如下：因为当前是否匹配是和前一个元素的状态紧密相关的，因此使用动态规划的思想
1、若p[j] == s[i]，则dp[j][i] = dp[j-1][i-1]；
2、若p[j] == '.'，则dp[j][i] = dp[j-1][i-1]；
3、若p[j] == '*'，则
   （i）若p[j-1] == s[i] 或 p[j-1] == '.'
		①dp[j][i] = dp[j][i-1]；（p中的模式a*在s中出现多次）
        ②dp[j][i] = dp[j-2][i-1]；（p中的模式a*在s中出现1次）
		③dp[j][i] = dp[j-2][i]；（p中的模式a*在s中出现0次）
	（ii）若p[j-1] != s[i]，则dp[j][i] = dp[j-2][i]；

代码就是由以上几种思路整理而来。
*/

bool isMatch(string s, string p){
	int s_len = s.length();
	int p_len = p.length();
	bool **dp;
	dp = new bool *[p_len + 1];
	for (int i = 0; i < p_len + 1; i++){
		dp[i] = new bool[s_len + 1];
	}
	dp[0][0] = 1;
	// 列表示p，行表示s,因为空串p只能匹配空串，其他都无能匹配
	for (int i = 1; i < s_len + 1; i++){
		dp[0][i] = 0;
	}
	// 初始化第0列，只有X*能匹配空串，如果有*，它的真值一定和p[0][j - 2]的相同（略过它之前的符号）
	for (int j = 1; j < p_len + 1; j++){
		dp[j][0] = j>1 && p[j - 1] == '*' && dp[j - 2][0];
	}
	// 动态规划变换方程编程
	for (int i = 1; i < s_len + 1; i++){
		for (int j = 1; j < p_len + 1; j++){
			if (p[j - 1] == '*'){
				// p[j] == '*'的几种情况组合，取并集
				dp[j][i] = dp[j - 2][i] || ((p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[j - 2][i - 1]) || ((p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[j][i - 1]);
			}
			else{   //只有当前字符完全匹配，才有资格传递dp[i-1][j-1] 真值。dp[j][i] = dp[j-1][i-1]的2种情况组合。
				dp[j][i] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[j - 1][i - 1];
			}
		}
	}
	return dp[p_len][s_len];
}

int main(){
	string s = "mississippi";
	string p = "mis*is*p*.";
	bool result = isMatch(s, p);
	cout << result << endl;
	return 0;
}