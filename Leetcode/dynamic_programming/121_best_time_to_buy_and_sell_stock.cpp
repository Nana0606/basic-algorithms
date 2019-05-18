# include <iostream>
# include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	// 主要点：因为必须是先买后卖，所以需要使用后面的元素，减去前面元素以获取利益最大化
	int min_price = INT_MAX;
	int maxPro = 0;
	for (int i = 0; i < prices.size(); i++){
		if (min_price > prices[i])
			min_price = prices[i];
		if (maxPro < (prices[i] - min_price))
			maxPro = prices[i] - min_price;
	}
	return maxPro;
}

int main(){
	vector<int> prices = {1, 9900};
	int result = maxProfit(prices);
	cout << result << endl;
	return 0;
}