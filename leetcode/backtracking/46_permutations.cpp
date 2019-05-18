# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//直接调用next_permutation()函数
/*
vector<vector<int>> permute(vector<int>& nums){
	vector<vector<int> > res;
	sort(nums.begin(), nums.end());
	do{
		res.push_back(nums);
	} while (next_permutation(nums.begin(), nums.end()));
	return res;
}
*/

void permuteRecursive(vector<int> & num, int begin, vector<vector<int> > & result){
	if (begin >= num.size()){
		result.push_back(num);
		return;
	}
	for (int i = begin; i < num.size(); i++){
		swap(num[begin], num[i]);
		permuteRecursive(num, begin + 1, result);
		//reset
		swap(num[begin], num[i]);
	}
}

//方法二：使用回溯法
vector<vector<int> > permute(vector<int> &num){
	vector<vector<int> > result;
	permuteRecursive(num, 0, result);
	return result;
}


int main(){
	vector<int> nums = { 1, 2, 3 };
	vector<vector<int> > res = permute(nums);
	for (int i = 0; i < int(res.size()); i++){
		for (int j = 0; j<int(res[0].size()); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

