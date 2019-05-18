# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int *dp = new int[n];
	dp[0] = nums[0];
	int max_value = nums[0];

	for (int i = 0; i < n; i++){
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		max_value = max(max_value, dp[i]);  //若取当前元素之前的序列，即从当前元素开始一个新的序列，则通过max_value记录。
	}
	return max_value;
}


int main(){
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -1, 4 };
	int result = maxSubArray(nums);
	cout << result << endl;
	return 0;
}