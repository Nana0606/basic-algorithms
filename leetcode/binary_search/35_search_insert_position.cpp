# include <iostream>
# include <vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
	/**
	先利用二分查找定位大体位置，再根据target和小范围元素的大小关系详细定位。
	*/
	int left = 0;
	int right = nums.size() - 1;
	
	while (left < right - 1){    //二分查找
		int mid = (left + right) / 2;
		if (nums[mid] == target){
			return mid;
		}
		else if (target > nums[mid]){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	if (left == right){    //当left >= right - 1时，可能出现与边界相等或者没有查找到元素的情况
		if (target == nums[left]){    //与边界相等
			return left;
		}
		else{     //与边界不等
			return target > nums[left] ? (right + 1) : left;
		}
	}
	else if (left == right - 1){
		if (target == nums[left]){   //与左边界相等
			return left;
		}
		else if (target == nums[right]){    //与右边界相等
			return right;
		}
		else if (target < nums[left]){    //比左边界小
			return left;
		}
		else if (target > nums[right]){    //比右边界大
			return right+1;
		}
		else{     //处在左边界和右边界中间
			return left + 1;
		}
	}
}

int main(){
	vector<int> nums = { 1, 2, 4, 6, 7};
	int target = 8;
	int result = searchInsert(nums, target);
	cout << result << endl;
	return 0;
}