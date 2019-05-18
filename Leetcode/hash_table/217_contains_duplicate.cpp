# include<iostream>
# include<vector>
# include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
	set<int> temp;
	for (int i = 0; i < nums.size(); i++){
		temp.insert(nums[i]);
		if (temp.size() != (i + 1)){
			return true;   //若已经不同了，直接跳出循环，返回true
			break;
		}
	}
	return nums.size() != temp.size();
}

int main(){
	vector<int> nums = { 1, 1, 2,3, 4, 1};
	bool res = containsDuplicate(nums);
	cout << res << endl;
	return 0;
}