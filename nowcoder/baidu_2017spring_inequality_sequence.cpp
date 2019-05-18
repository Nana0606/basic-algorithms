# include <iostream>
using namespace std;

//题目：不等式数列
//地址：https://www.nowcoder.com/question/next?pid=4998655&qid=95827&tid=20646504

int main(){
	int n, k;
	cin >> n >> k;
	//数字不能为0个，但是符号可以为0个，所以必须从0开始，但是考虑到数字，需要有n+1个。但是符号有n个就可以了
	int **dp = new int*[n+1];
	for (int i = 0; i < n+1; i++){
		dp[i] = new int[n];
	}
	for (int i = 0; i < n+1; i++){
		for (int j = 0; j < n; j++){
			dp[i][j] = 0;
		}
	}
	dp[1][0] = 1;   //因为符号始终比数字少一个
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < n; j++){
			if (j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] * (i - j) + dp[i - 1][j] * (j + 1)) % 2017;
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}