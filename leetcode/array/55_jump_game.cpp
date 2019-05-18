# include <iostream>
# include<algorithm>
# include <vector>
using namespace std;

bool canJump(vector<int>& nums){
	int n = nums.size();
	int index = 0, reach = 0;
	// index <= reach,����ǳ�������Խ���м����������
	for (index = 0, reach = 0; index < n&&index <= reach; index++){
		// index+ nums[index]��ʾ�ӵ�ǰ�������ߵ�����
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