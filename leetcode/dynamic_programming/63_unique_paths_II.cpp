# include <iostream>
# include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	//注意：这个第一行和第一列的初始化，如果中途出现了障碍物，则会阻止其进行，dp=0
	vector<vector<int> > dp(int(obstacleGrid.size()), vector<int>(int(obstacleGrid[0].size()), 1));
	dp[0][0] = (obstacleGrid[0][0] == 1 ? 0 : 1);
	for (int i = 1; i < int(obstacleGrid.size()); i++){
		dp[i][0] = (obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0]);
	}
	for (int i = 1; i < int(obstacleGrid[0].size()); i++){
		dp[0][i] = (obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1]);
	}

	for (int i = 1; i<int(obstacleGrid.size()); i++){
		for (int j = 1; j < int(obstacleGrid[0].size()); j++){
			if (obstacleGrid[i][j] == 1) dp[i][j] = 0;  //若有阻碍，则在这之前从没有1条路径开始从开始走到最后
			else{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[int(obstacleGrid.size()) - 1][int(obstacleGrid[0].size())-1];
}

int main() {
	vector<vector<int>> obstacleGrid = { { 0, 1 } };
	int res = uniquePathsWithObstacles(obstacleGrid);
	cout << res << endl;
	return 0;
}