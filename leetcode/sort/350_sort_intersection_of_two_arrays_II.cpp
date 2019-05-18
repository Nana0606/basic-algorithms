# include <iostream>
# include <vector>
# include <map>
using namespace std;

/**
借助map统计出现次数
*/

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	map<int, int> dict;
	vector<int> result;
	//统计nums2出现的数字及其出现的次数。
	for (int i = 0; i < (int)nums1.size(); i++){
		dict[nums1[i]]++;
	}
	//遍历nums2进行查找，主要的技巧点在于--dict[nums2[j]]，这个--相当于把前一次的给减掉
	for (int j = 0; j < (int)nums2.size(); j++){
		if (--dict[nums2[j]] >= 0){
			result.push_back(nums2[j]);
		}
	}
	return result;
}

int main(){
	vector<int> nums1 = { 4, 9, 5 };
	vector<int> nums2 = { 9, 4, 9, 8, 4 };
	vector<int> result = intersect(nums1, nums2);
	vector<int>::iterator it;
	for (it = result.begin(); it < result.end(); it++){
		cout << " " << *it;
	}
	cout << endl;
	return 0;
}