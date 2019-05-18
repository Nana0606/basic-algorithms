# include <iostream>
# include <vector>
using namespace std;

// 方法一：使用快排，Success
/*
vector<int>& quicksort(vector<int>& nums, int left, int right){
	int i = left, j = right;
	int temp = nums[left];
	if (i > j){
		return nums;
	}
	while (i < j){
		while ((nums[j] >= temp) && (i < j)){
			j--;
		}
		while ((nums[i] <= temp) && (i < j)){
			i++;
		}
		if (i < j){  //交换nums[i]和nums[j]
			int value = nums[i];
			nums[i] = nums[j];
			nums[j] = value;
		}
	}
	// i==j,交换其和枢纽元素
	nums[left] = nums[i];
	nums[i] = temp;
	if (i > 0){   //防止枢纽是第一个元素
		quicksort(nums, left, i - 1);
	}
	if (i < right){   //防止枢纽是最后一个元素
		quicksort(nums, i + 1, right);
	}
	return nums;
}

void sortColors(vector<int>& nums) {
	vector<int>& data = quicksort(nums, 0, int(nums.size())-1);
	nums = data;
}
*/

//方法二：使用计数
struct Count{
	int num0=0;
	int num1=0;
	int num2=0;
};

void sortColors(vector<int>& nums) {
	Count data;
	for (int i = 0; i < int(nums.size()); i++){
		if (nums[i] == 0) data.num0++;
		else if (nums[i] == 1) data.num1++;
		else if (nums[i] == 2) data.num2++;
	}
	for (int i = 0; i < data.num0; i++){
		nums[i] = 0;
	}
	for (int i = 0; i < data.num1; i++){
		nums[data.num0 + i] = 1;
	}
	for (int i = 0; i < data.num2; i++){
		nums[data.num0 + data.num1 + i] = 2;
	}
}

int main(){

	vector<int> nums = { 0, 0, 1, 1, 2, 0 };
	sortColors(nums);
	for (int i = 0; i < int(nums.size()); i++){
		cout << nums[i] << " ";
	}
	return 0;
}