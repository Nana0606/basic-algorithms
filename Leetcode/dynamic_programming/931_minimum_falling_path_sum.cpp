# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
using namespace std;


// AC。使用DP，DP数组为二维数组，因为前后有影响，所以需要使用二维DP数组。
int minFallingPathSum(vector<vector<int>>& A) {
	int min_value = INT_MAX;
	vector<int> temp(int(A.size()), 0);
	vector<vector<int> > dp(int(A.size()), temp);
	for (int i = 0; i < int(A.size()); i++){
		dp[0][i] = A[0][i];
	}
	for (int i = 1; i < int(A.size()); i++){
		for (int j = 0; j < int(A.size()); j++){
			if (j == 0){
				dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][0];
			}
			else if (j == int(A.size()) - 1){
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j-1]) + A[i][j];
			}
			else{
				dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]) + A[i][j];
			}
		}
	}
	cout << endl;
	for (int i = 0; i < int(A.size()); i++){
		min_value = min(dp[int(A.size()) - 1][i], min_value);
	}
	return min_value;
}


int main(){
	vector<vector<int> > A = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int res = minFallingPathSum(A);
	cout << res << endl;
	return 0;
}