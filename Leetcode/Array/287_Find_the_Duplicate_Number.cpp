# include <iostream>
# include <set>
# include <vector>
using namespace std;

//方法一：利用set的特性
/*
int findDuplicate(vector<int>& nums) {
	set<int> temp;
	for (int i = 0; i < int(nums.size()); i++){
		temp.insert(nums[i]);
		if (int(temp.size()) < (i + 1)) return nums[i];
	}
	return 0;
}
*/

//利用重复元素带来的访问元素的循环体
int findDuplicate(vector<int>& nums){
	int slow = nums[0];  //slow开始的是第一个元素
	int fast = nums[nums[0]];  //fast开始的第二个元素

	//第一个循环是为了找到一个循环体，slow==fast最后的收敛点一定在环中的某一个位置上。
	while (slow != fast){
		slow = nums[slow];
		fast = nums[nums[fast]];
	}

	//第二个循环是为了找到重复元素，也就是循环体的开始
	fast = 0;  // fast开始从头开始去查找
	while (slow != fast){
		fast = nums[fast];
		slow = nums[slow];
	}
	return slow;
}


int main(){
	vector<int> nums = { 1, 3, 4, 2, 2};
	int res = findDuplicate(nums);
	cout << res << endl;
	return 0;
}