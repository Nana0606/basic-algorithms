# include <iostream>
# include <vector>
using namespace std;

// AC, easy
//使用桶排序的方法，注意因为nums缺失一条数据，所以temp的长度比nums长1
int missingNumber(vector<int>& nums) {
	vector<int> temp(nums.size() + 1, -1);
	for (int i = 0; i < nums.size(); i++){
		temp[nums[i]] = 1;
	}
	for (int i = 0; i < temp.size(); i++){
		if (temp[i] != 1){
			return i;
		}
	}
	return 0;
}

int main(){
	vector<int> nums = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int res = missingNumber(nums);
	cout << res << endl;
	return 0;
}