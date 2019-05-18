# include <iostream>
# include <cmath>
using namespace std;

// AC����Ҫע��㣺i*i <= n
bool isPrime(int n){
	if (n <= 1) return false;
	//ʹ��i <= (int)sqrt(n)�ᳬʱ,������Ҫʹ��i*i <= n;
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