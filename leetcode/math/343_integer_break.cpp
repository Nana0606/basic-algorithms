# include <iostream>
using namespace std;

// 利用最优化思想，可以得出当每个数都是e的时候，乘积取最大值，这里取最接近e的3（有证明），对于比较小的数字，这里单独讨论
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