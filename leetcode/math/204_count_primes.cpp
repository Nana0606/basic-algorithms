# include <iostream>
# include <cmath>
using namespace std;

// AC，主要注意点：i*i <= n
bool isPrime(int n){
	if (n <= 1) return false;
	//使用i <= (int)sqrt(n)会超时,所以需要使用i*i <= n;
	for (int i = 2; i*i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int countPrimes(int n) {
	int count = 0;
	for (int i = 2; i < n; i++){
		if (isPrime(i)) count++;
	}
	return count;
}

int main(){
	int n = 10;
	int res = countPrimes(n);
	cout << res << endl;
	return 0;
}