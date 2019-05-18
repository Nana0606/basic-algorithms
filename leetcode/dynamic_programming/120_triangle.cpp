# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
	//从后向前看可以看到全局的，因为最下面一层的节点是最全的，从上到下容易陷入局部最优解。
	vector<int> dp = triangle[triangle.size() - 1];
	for (int i = triangle.size() - 2; i >= 0; i--){
		for (int j = 0; j <= i; j++){
			dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
		}
	}
	return dp[0];
}

int main(){
	// int triangle[][4] = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	vector<vector<int> > triangle = { { -1 }, { 2, 3 }, { 1, -1, -3 } };
	int result = minimumTotal(triangle);
	cout << result << endl;
	return 0;

}