# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/*
本题需要注意：相邻节点不能同时都进入,因此若i-1进入，则i不能进入
*/

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	if (n <= 2) return *max_element(nums.begin(), nums.end());

	int *dp = new int[n];
	dp[0] = nums[0];
	dp[1] = max(dp[0], nums[1]);
	for (int i = 2; i < n; i++){
		//如果当前值，即nums[i]不进入，则i-1可以进入，即dp[i - 1]；
		//如果当前值，即nums[i]进入，则i-1不可进入，即dp[i - 2] + nums[i]
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	return dp[n - 1];
}

int main(){
	vector<int> nums = { 1};
	int result = rob(nums);
	cout << result << endl;
	return 0;
}