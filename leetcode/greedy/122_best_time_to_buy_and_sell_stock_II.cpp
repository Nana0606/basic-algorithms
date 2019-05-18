# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

/*
之前在考虑，如果第1天买，第2天卖，但是第3天的卖出价格很高，这种情况，但实际上，可以考虑在同一天可以同时买入和卖出（这个就相当于这一天没有进行任何操作），
主要是简化思路为：若i天卖出i-1天可以盈利，则i-1天买入，i天卖出，当天先卖出之前买的，在买留着以后卖也是可以的（这就简化了类似{1，2，3，4，5}这种case的问题）
*/
int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1) return 0;
	int profit = 0;
	for (int i = 1; i < prices.size(); i++){
		//如果i天卖出i-1天的可以盈利，则i-1天买入，i天卖出
		profit += max(prices[i] - prices[i - 1], 0);
	}
	return profit;
}

int main(){
	vector<int> nums = { 7, 6, 4, 3, 1 };
	int result = maxProfit(nums);
	cout << result << endl;
	return 0;
}