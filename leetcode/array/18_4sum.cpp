# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;


//±©Á¦
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	set<vector<int> > res;
	vector<vector<int> > result;
	for (int i = 0; i < int(nums.size()) - 3; i++){
		for (int j = i + 1; j < int(nums.size()) - 2; j++){
			for (int k = j + 1; k < int(nums.size()) - 1; k++){
				for (int p = k + 1; p < int(nums.size()); p++){
					if (nums[i] + nums[j] + nums[k] + nums[p] == target){
						vector<int> temp = { nums[i], nums[j], nums[k], nums[p]};
						sort(temp.begin(), temp.end());
						res.insert(temp);
					}
				}
			}
		}
	}
	
	set<vector<int> > ::iterator it;
	for (it = res.begin(); it != res.end(); it++){
		result.push_back(*it);
	}
	return result;
}


int main(){
	vector<int> nums= {-5, 5, 4, -3, 0, 0, 4, -2};
	int target = -1;
	vector<vector<int>> result = fourSum(nums, target);
	for (int i = 0; i < int(result.size()); i++){
		for (int j = 0; j < int(result[i].size()); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}