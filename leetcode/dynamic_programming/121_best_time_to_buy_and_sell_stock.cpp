# include <iostream>
# include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	// ��Ҫ�㣺��Ϊ���������������������Ҫʹ�ú����Ԫ�أ���ȥǰ��Ԫ���Ի�ȡ�������
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