# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// 变形的二分查找，加入nums[mid] > first_value的条件，作为二分查找的终止点，并返回二分查找的范围
vector<int> binary_search(vector<int>& nums, int left, int right, int first_value){
	//二分查找的思想
	int mid = (left + right) / 2;
	vector<int> result;
	while (left < right && nums[mid] > first_value){
		left = mid + 1;
		mid = (left + right) / 2;
	}

	result.push_back(left);
	result.push_back(right);
	return result;
}

int findMin(vector<int>& nums) {
	//使用二分查找将最小值缩小到了一定范围内，在这个范围内遍历找到最小值
	int first_value = nums[0];
	vector<int> result = binary_search(nums, 0, int(nums.size()) - 1, first_value);

	int min_value = min(nums[result[0]], first_value);    //有可能是完全升序的一个序列，即未有反转的部分。
	for (int i = result[0] + 1; i <= result[1]; i++){
		min_value = min(min_value, nums[i]);
	}
	return min_value;
}

int main(){
	vector<int> nums = { 1, 2, 3 };
	int min = findMin(nums);
	cout << min << endl;
	return 0;
}