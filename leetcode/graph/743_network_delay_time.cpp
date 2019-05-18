# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> dp(N+1, INT_MAX);    //记录从K走到当前点的最小值
		dp[K] = 0;   //从K点到K点的最小值是0
		for (int i = 1; i <= N; i++){  //循环的原因是初始点是K，所以第一次循环只能得到一部分以K开头，和不断往下运算有关系的点的值，还有一部分点的值可能还没有计算得到，所以需要不断循环。
			for (vector<int> temp : times){
				int start = temp[0];
				int end = temp[1];
				int time = temp[2];
				if (dp[start] != INT_MAX && dp[end] > dp[start] + time){
					dp[end] = dp[start] + time;  //找到最小值
				}
			}
		}
		
		int max_val = 0;   //dp[]找到了K点到其余所有节点的最小值，为了保证每个节点都被访问到，所以这里需要取最大值
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