# include <iostream>
using namespace std;

// �������Ż�˼�룬���Եó���ÿ��������e��ʱ�򣬳˻�ȡ���ֵ������ȡ��ӽ�e��3����֤���������ڱȽ�С�����֣����ﵥ������
int integerBreak(int n) {
	if (n == 2) return 1;
	if (n == 3) return 2;
	int res = 1;
	while (n > 4){
		res *= 3;
		n -= 3;
	}
	return n * res;
}

int main(){
	int n = 10;
	int res = integerBreak(n);
	cout << res << endl;
	return 0;
}