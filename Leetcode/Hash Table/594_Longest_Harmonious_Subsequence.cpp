# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;

/**
主要思路：
Step1：先使用一个map统计所有数字出现的次数
Step2：如果num出现了n次，num+1出现了m次，则这个为1的差值序列长度为m+n
注意：对于num和num+1都要当过一次最小值。
*/
class Solution {
public:
	int findLHS(vector<int>& nums) {
		map<int, int> mymap;
		map<int, int>::iterator it;
		map<int, int>::iterator temp;
		int max_val = 0;
		//统计mymap中词出现的个数
		for (int i = 0; i < int(nums.size()); i++){
			it = mymap.find(nums[i]);
			if (it != mymap.end()){ //已经存在
				mymap[nums[i]] ++;
			}
			else{
				mymap.insert(pair<int, int>(nums[i], 1));
			}
		}
		for (it = mymap.begin(); it != mymap.end(); it++){
			int num = (*it).first;
			temp = mymap.find(num + 1);
			if (temp != mymap.end()){
				max_val = max(max_val, ((*it).second + (*temp).second));
			}
		}
		return max_val;
	}
};

int main(){
	vector<int> nums;
	int value;
	while (cin >> value && value != (-1)){
		nums.push_back(value);
	}
	Solution solution;
	int res = solution.findLHS(nums);
	cout << res << endl;
	return res;
}