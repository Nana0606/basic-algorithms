# include <iostream>
# include<algorithm>
# include <vector>
using namespace std;

bool canJump(vector<int>& nums){
	int n = nums.size();
	int index = 0, reach = 0;
	// index <= reach,这个非常巧妙，可以解决中间断续的问题
	for (index = 0, reach = 0; index < n&&index <= reach; index++){
		// index+ nums[index]表示从当前步可以走到哪里
		reach = max(index + nums[index], reach);  
	}
	return reach >= n - 1;
}

int main(){
	vector<int> nums = {3, 2, 1, 0 ,4};
	bool res = canJump(nums);
	cout << res << endl;
	return 0;
}