# include <iostream>
using namespace std;

//��Ŀ������ʽ����
//��ַ��https://www.nowcoder.com/question/next?pid=4998655&qid=95827&tid=20646504

int main(){
	int n, k;
	cin >> n >> k;
	//���ֲ���Ϊ0�������Ƿ��ſ���Ϊ0�������Ա����0��ʼ�����ǿ��ǵ����֣���Ҫ��n+1�������Ƿ�����n���Ϳ�����
	int **dp = new int*[n+1];
	for (int i = 0; i < n+1; i++){
		dp[i] = new int[n];
	}
	for (int i = 0; i < n+1; i++){
		for (int j = 0; j < n; j++){
			dp[i][j] = 0;
		}
	}
	dp[1][0] = 1;   //��Ϊ����ʼ�ձ�������һ��
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < n; j++){
			if (j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] * (i - j) + dp[i - 1][j] * (j + 1)) % 2017;
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}