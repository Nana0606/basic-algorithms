# include <iostream>
# include <vector>
using namespace std;

/*
本题代码的技巧性还是比较强的、
1、外层循环限制了满足条件的连续数组的右边界，但是除了右边界确定之外，为了满足最短的连续数组的要求，需要限制左边界
2、左边界的限制通过sum -= nums[start++];来限制，所以里面的判断需要使用while而不是if，因为要找满足条件的最短序列
3、当while循环不满足时，start不需要从0开始，直接从当前值开始，（因为从0开始的while循环已经操作过，说明已有一个满足条件，现在i++，这个判断无意义）
*/

int minSubArrayLen(int s, vector<int>& nums) {
	int minLen = INT_MAX;
	int start = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++){
		sum += nums[i];
		while (sum >= s){
			minLen = (minLen > (i - start + 1) ? (i - start + 1) : minLen);
			sum -= nums[start++];
		}
	}
	return minLen == INT_MAX ? 0 : minLen;
}


int main(){
	int s = 9;
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	int minLen = minSubArrayLen(s, nums);
	cout << minLen << endl;
	return 0;
}