# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
	//�Ӻ���ǰ�����Կ���ȫ�ֵģ���Ϊ������һ��Ľڵ�����ȫ�ģ����ϵ�����������ֲ����Ž⡣
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