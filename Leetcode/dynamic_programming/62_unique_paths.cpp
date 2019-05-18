# include <iostream>
# include <vector>
using namespace std;

//最简单的动态规划问题，当前位置只有可能来自左侧或者上侧
int uniquePaths(int m, int n) {
	vector<vector<int> > dp(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int main(){
	int m = 7, n = 3;
	int res = uniquePaths(m, n);
	cout << res << endl;
	return 0;
}