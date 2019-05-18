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
		max_value = max(max_value, dp[i]);  //��ȡ��ǰԪ��֮ǰ�����У����ӵ�ǰԪ�ؿ�ʼһ���µ����У���ͨ��max_value��¼��
	}
	return max_value;
}


int main(){
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -1, 4 };
	int result = maxSubArray(nums);
	cout << result << endl;
	return 0;
}