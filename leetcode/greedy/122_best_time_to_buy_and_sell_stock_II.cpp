# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

/*
֮ǰ�ڿ��ǣ������1���򣬵�2���������ǵ�3��������۸�ܸߣ������������ʵ���ϣ����Կ�����ͬһ�����ͬʱ�����������������൱����һ��û�н����κβ�������
��Ҫ�Ǽ�˼·Ϊ����i������i-1�����ӯ������i-1�����룬i������������������֮ǰ��ģ����������Ժ���Ҳ�ǿ��Եģ���ͼ�������{1��2��3��4��5}����case�����⣩
*/
int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1) return 0;
	int profit = 0;
	for (int i = 1; i < prices.size(); i++){
		//���i������i-1��Ŀ���ӯ������i-1�����룬i������
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