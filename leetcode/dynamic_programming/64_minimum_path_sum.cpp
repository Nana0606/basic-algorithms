# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	//动态方程为：s[i][j] = min(s[i-1][j], s[i][j-1]) + grid[i][j];
	int m = grid.size();    //行数
	int n = grid[0].size();   //列数
	vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
	//因为第一行和第一列没有i-1的操作，所以先初始化第一行和第一列
	for (int i = 1; i < m; i++){    //初始化第一列
		sum[i][0] = sum[i - 1][0] + grid[i][0];
	}
	for (int j = 1; j < n; j++){   //初始化第一列
		sum[0][j] = sum[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++){
			sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
		}
	return sum[m - 1][n - 1];
}

int main(){
	vector<vector<int>> grid = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
	int min_value = minPathSum(grid);
	cout << min_value << endl;
	return 0;
}