# include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
	if (n <= 0) return false;
	else{
		while (n > 1){    // 当n大于1时，若满足是3的幂，则每次除以3之后都是3的幂，直到n==1
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