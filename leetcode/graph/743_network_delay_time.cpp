# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> dp(N+1, INT_MAX);    //��¼��K�ߵ���ǰ�����Сֵ
		dp[K] = 0;   //��K�㵽K�����Сֵ��0
		for (int i = 1; i <= N; i++){  //ѭ����ԭ���ǳ�ʼ����K�����Ե�һ��ѭ��ֻ�ܵõ�һ������K��ͷ���Ͳ������������й�ϵ�ĵ��ֵ������һ���ֵ��ֵ���ܻ�û�м���õ���������Ҫ����ѭ����
			for (vector<int> temp : times){
				int start = temp[0];
				int end = temp[1];
				int time = temp[2];
				if (dp[start] != INT_MAX && dp[end] > dp[start] + time){
					dp[end] = dp[start] + time;  //�ҵ���Сֵ
				}
			}
		}
		
		int max_val = 0;   //dp[]�ҵ���K�㵽�������нڵ����Сֵ��Ϊ�˱�֤ÿ���ڵ㶼�����ʵ�������������Ҫȡ���ֵ
		for (int i = 1; i <= N; i++){
			max_val = max(dp[i], max_val);
		}
		return max_val == INT_MAX ? -1 : max_val;
 	}
};

int main(){
	vector<vector<int> > times = { { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 } };
	int N = 4;
	int K = 2;
	Solution solution;
	int res = solution.networkDelayTime(times, N, K);
	cout << res << endl;
	return 0;
}