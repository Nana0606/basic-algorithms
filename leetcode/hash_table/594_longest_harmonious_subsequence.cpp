# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;

/**
��Ҫ˼·��
Step1����ʹ��һ��mapͳ���������ֳ��ֵĴ���
Step2�����num������n�Σ�num+1������m�Σ������Ϊ1�Ĳ�ֵ���г���Ϊm+n
ע�⣺����num��num+1��Ҫ����һ����Сֵ��
*/
class Solution {
public:
	int findLHS(vector<int>& nums) {
		map<int, int> mymap;
		map<int, int>::iterator it;
		map<int, int>::iterator temp;
		int max_val = 0;
		//ͳ��mymap�дʳ��ֵĸ���
		for (int i = 0; i < int(nums.size()); i++){
			it = mymap.find(nums[i]);
			if (it != mymap.end()){ //�Ѿ�����
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