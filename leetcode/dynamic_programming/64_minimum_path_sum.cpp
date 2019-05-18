# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	//��̬����Ϊ��s[i][j] = min(s[i-1][j], s[i][j-1]) + grid[i][j];
	int m = grid.size();    //����
	int n = grid[0].size();   //����
	vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
	//��Ϊ��һ�к͵�һ��û��i-1�Ĳ����������ȳ�ʼ����һ�к͵�һ��
	for (int i = 1; i < m; i++){    //��ʼ����һ��
		sum[i][0] = sum[i - 1][0] + grid[i][0];
	}
	for (int j = 1; j < n; j++){   //��ʼ����һ��
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