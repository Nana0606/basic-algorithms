# include <iostream>
# include <string>
using namespace std;

/**
Accepted
ʹ�ö�̬�滮����̬�滮������Ҫ��ϸ���ǵģ���Ҫ��������
	1����̬�任���̡�
	2����ʼ�������顣
�ο�����: https://blog.csdn.net/hk2291976/article/details/51165010

��Ҫ˼·���£���Ϊ��ǰ�Ƿ�ƥ���Ǻ�ǰһ��Ԫ�ص�״̬������صģ����ʹ�ö�̬�滮��˼��
1����p[j] == s[i]����dp[j][i] = dp[j-1][i-1]��
2����p[j] == '.'����dp[j][i] = dp[j-1][i-1]��
3����p[j] == '*'����
   ��i����p[j-1] == s[i] �� p[j-1] == '.'
		��dp[j][i] = dp[j][i-1]����p�е�ģʽa*��s�г��ֶ�Σ�
        ��dp[j][i] = dp[j-2][i-1]����p�е�ģʽa*��s�г���1�Σ�
		��dp[j][i] = dp[j-2][i]����p�е�ģʽa*��s�г���0�Σ�
	��ii����p[j-1] != s[i]����dp[j][i] = dp[j-2][i]��

������������ϼ���˼·���������
*/

bool isMatch(string s, string p){
	int s_len = s.length();
	int p_len = p.length();
	bool **dp;
	dp = new bool *[p_len + 1];
	for (int i = 0; i < p_len + 1; i++){
		dp[i] = new bool[s_len + 1];
	}
	dp[0][0] = 1;
	// �б�ʾp���б�ʾs,��Ϊ�մ�pֻ��ƥ��մ�������������ƥ��
	for (int i = 1; i < s_len + 1; i++){
		dp[0][i] = 0;
	}
	// ��ʼ����0�У�ֻ��X*��ƥ��մ��������*��������ֵһ����p[0][j - 2]����ͬ���Թ���֮ǰ�ķ��ţ�
	for (int j = 1; j < p_len + 1; j++){
		dp[j][0] = j>1 && p[j - 1] == '*' && dp[j - 2][0];
	}
	// ��̬�滮�任���̱��
	for (int i = 1; i < s_len + 1; i++){
		for (int j = 1; j < p_len + 1; j++){
			if (p[j - 1] == '*'){
				// p[j] == '*'�ļ��������ϣ�ȡ����
				dp[j][i] = dp[j - 2][i] || ((p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[j - 2][i - 1]) || ((p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[j][i - 1]);
			}
			else{   //ֻ�е�ǰ�ַ���ȫƥ�䣬�����ʸ񴫵�dp[i-1][j-1] ��ֵ��dp[j][i] = dp[j-1][i-1]��2�������ϡ�
				dp[j][i] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[j - 1][i - 1];
			}
		}
	}
	return dp[p_len][s_len];
}

int main(){
	string s = "mississippi";
	string p = "mis*is*p*.";
	bool result = isMatch(s, p);
	cout << result << endl;
	return 0;
}