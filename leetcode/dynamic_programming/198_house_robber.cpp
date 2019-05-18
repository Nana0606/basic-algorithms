# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/*
������Ҫע�⣺���ڽڵ㲻��ͬʱ������,�����i-1���룬��i���ܽ���
*/

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	if (n <= 2) return *max_element(nums.begin(), nums.end());

	int *dp = new int[n];
	dp[0] = nums[0];
	dp[1] = max(dp[0], nums[1]);
	for (int i = 2; i < n; i++){
		//�����ǰֵ����nums[i]�����룬��i-1���Խ��룬��dp[i - 1]��
		//�����ǰֵ����nums[i]���룬��i-1���ɽ��룬��dp[i - 2] + nums[i]
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