# include <iostream>
# include <algorithm>
using namespace std;

// AC
class Solution {
public:
	int distinctSubseqII(string S) {
		long mod = pow(10, 9) + 7;
		int *dp = new int[int(S.size()) + 1];
		for (int i = 0; i < int(S.size()) + 1; i++){
			dp[i] = 0;
		}
		int *last = new int[26];   //存储的是下标+'a'出现在S中的最后一次的位置。
		for (int i = 0; i < 26; i++){  //只保留此字母最后出现的一个位置
			last[i] = -1;
		}

		dp[0] = 1;   //此时表示为空时
		for (int i = 0; i < int(S.size()); i++){
			int index = S[i] - 'a';
			cout << "index is::" << index << endl;
			dp[i+1] = dp[i] * 2 % mod;
			if (last[index] >= 0){
				cout << "进入last[index] >= 0" << endl;
				dp[i+1] -= dp[last[index]];   
				cout << "dp[i+1] is::" << dp[i + 1] << endl;
			}
			dp[i + 1] %= mod;
			cout << "dp i+1 " << i+1 << " " << dp[i+1] << endl;
			last[index] = i;
		}
		dp[int(S.size())] --;
		if (dp[int(S.size())] < 0)
			dp[int(S.size())] += mod;
		int res = dp[int(S.size())];
		delete[] last;
		delete[] dp;
		return res;
	}
};

int main(){
	string str = "ophajrtskwvemzzpybodijlrnixjzwuhllbteqcnpatxwbfbhyhnhntypjsmiskryyircromuqpflmkjycxxeokajpfcgmhebxqqoftauketrwoocxqflasfmcoivpslmsvafvsjcwabansddjbhhrrelcfrgwgssbuhfjplkpxfdzvjwtmlbphxeasvacwtvslbnpflmlasxqfeegkbgguuawscvuzrfxiaepkvzrrrsnezluebtwcpnivgnetmlrdyytsooumbsnewejceeaajbzpqphghsafysqbzxvda";
	Solution solution;
	int res = solution.distinctSubseqII(str);
	cout << res << endl;
	return 0;
}