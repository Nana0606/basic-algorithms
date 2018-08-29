# include <iostream>
# include <string>
using namespace std;

/**
ʹ�û��ݷ���������ο�https://blog.csdn.net/hk2291976/article/details/51165010
ע��ע��: ���case��������ģ�
		string s = "aaa";
		string p = "ab*a*c*a";
		��Ϊ�ڴӺ���ǰ�����Ĺ����У�a*�����е�a��ƥ�����ˣ������ʼ��aû��ƥ��ѡ��
*/

static const int FRONT = -1;    //��ֹ����Խ�磬ֹͣ��ʶ
bool myMatch(string s, int i, string p, int j);    //��������

bool isMatch(string s, string p){
	return myMatch(s, s.length() - 1, p, p.length() - 1);
}

bool myMatch(string s, int i, string p, int j){
	// Step1: ��������ֹ��������ֹ
	if (j == FRONT){
		if (i == FRONT)
			return true;
		else
			return false;
	}
	//��p[j] == '*'����ǰ����ַ����Գ���0�λ���
	if (p[j] == '*'){
		if (i > FRONT && (p[j - 1] == s[i] || p[j - 1] == '.'))
			return myMatch(s, i - 1, p, j);
		else
			return myMatch(s, i, p, j - 2);
	}
	//��p[j] == '.'����s�п����������ַ�
	if (p[j] == '.'){
		return myMatch(s, i - 1, p, j - 1);
	}
	//��p[j] != '*' && p[j] != '.'����˵�����������ַ���ֻ���ж϶�Ӧ�ַ��Ƿ���ȼ���
	if (p[j] != '*' && p[j] != '.'){
		if (s[i] == p[j]){
			return myMatch(s, i - 1, p, j - 1);
		}
		else
			return false;
	}
}


int main(){
	string s = "aaa";
	string p = "ab*a*c*a";
	bool result = isMatch(s, p);
	cout << result << endl;
	return 0;
}