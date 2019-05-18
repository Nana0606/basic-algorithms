# include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
	if (n <= 0) return false;
	else{
		while (n > 1){    // ��n����1ʱ����������3���ݣ���ÿ�γ���3֮����3���ݣ�ֱ��n==1
			if (n % 3 != 0) return false;
			n /= 3;
		}
		if (n == 1) return true;
	}
}

int main(){
	int n = 45;
	bool res = isPowerOfThree(n);
	cout << res << endl;
	return 0;
}