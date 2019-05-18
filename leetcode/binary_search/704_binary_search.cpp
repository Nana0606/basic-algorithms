# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int res = binarySearch(nums, 0, nums.size()-1, target);
		return res;
	}
	int binarySearch(vector<int>& nums, int left, int right, int target){
		int mid = (left + right) / 2;
		if (left <= right){
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target){
				left = mid + 1;
				return binarySearch(nums, left, right, target);
			}
			else if (nums[mid] > target){
				right = mid - 1;
				return binarySearch(nums, left, right, target);
			}
		}
		else {
			return -1;
		}
	}
};

int main(){
	vector<int> nums = {5};
	int target = 5;
	Solution solution;
	int res = solution.search(nums, target);
	cout << res << endl;
	return 0;
}