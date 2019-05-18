# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// 自定义compare函数
//bool cmp(int a, int b){
//	return a > b;
//}

//方法一，直接调用algorithm中的sort算法
//int findKthLargest(vector<int>& nums, int k) {
//	sort(nums.begin(), nums.end());
//	return nums[nums.size() - k];
//}

//方法二：借助分治法的思想
int findKlargest(vector<int>& nums, int left, int right, int k){
	int i = left, j = right;
	int temp = nums[left];
	if (i > j)
		return -100;
	while (i < j){
		while ((nums[j] <= temp) && (i < j)){
			j--;
		}
		while ((nums[i] >= temp) && (i < j)){
			i++;
		}
		if (i < j){
			swap(nums[i], nums[j]);
		}
	}

	nums[left] = nums[i];   //快排中找到枢纽的正确位置
	nums[i] = temp;

	if (i < k - 1){  
		findKlargest(nums, i +1, right, k);
	}
	else if (i > k - 1){
		findKlargest(nums, left, i-1, k);
	} 
	else{   //若i == k-1，说明找到正确位置对应的元素
		return temp;
	}
}

int findKthLargest(vector<int>& nums, int k){
	int res = findKlargest(nums, 0, nums.size() - 1, k);
	return res;
}

int main(){
	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
	int k = 2;
	int res = findKthLargest(nums, k);
	cout << res << endl;
	return 0;
}