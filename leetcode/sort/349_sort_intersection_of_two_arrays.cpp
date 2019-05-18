# include <iostream>
# include <set>
# include <vector>
using namespace std;

/**
借助set，方便进行count出现次数的统计
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	set<int> nums1_set(nums1.begin(), nums1.end());    //转化为set方便使用count函数
	vector<int> result;
	for (int elem : nums2){
		if (nums1_set.count(elem) > 0){
			result.push_back(elem);
			nums1_set.erase(elem);     //**为了防止生成的result中有重复数据，因为擦除之后，nums1_set.count(elem)=0，所以不会二次添加
		}
	}
	return result;
}

int main(){
	vector<int> nums1_vec = { 4, 9, 5 };
	vector<int> nums2_vec = { 9, 4, 9, 8, 4 };
	vector<int> result = intersection(nums1_vec, nums2_vec);
	vector<int>::iterator it;
	for (it = result.begin(); it < result.end(); it++){
		cout << " " << *it << endl;
	}
	cout << endl;
	return 0;
}