# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

bool isUgly(int num, vector<int>& primes) {
	if (num <= 0) return false;
	if (num == 1) return true;
	while (num != 1){
		int i = 0;
		int flag = 0;    //加入了flag的限制，因为在这一轮循环中，只要有一个是可以被整除的，则不能直接判断为false
		for (i = 0; i < primes.size(); i++){
			if (num == 1) return true;   
			while(num % primes[i] == 0){
				num /= primes[i];
				flag = 1;
			}
		}
		if (flag == 0) return false;
	}
	return true;
}

/**
//最后一个case超时
int nthSuperUglyNumber(int n, vector<int>& primes) {
	int max_value = 1;
	if (n == 1)
		return max_value;
	int circle = 2;
	for (int i = 2; i <= n; i++){
		while (!isUgly(circle, primes)){
			circle++;
		}
		max_value = circle;
		circle++;
		//cout << max_value << endl;
	}
	return max_value;
}
*/

// AC
int nthSuperUglyNumber(int n, vector<int>& primes){
	if (n <= 0) return false;
	if (n == 1) return true;
	int *index = new int[primes.size()];
	for (int i = 0; i < primes.size(); i++){
		index[i] = 0;     //表示primes[i]已经出现的次数
	}
	vector<int> res(n);    //注意存储的n个数据，因此大小为n
	res[0] = 1;
	for (int i = 1; i < n; i++){
		int min_value = res[index[0]] * primes[0];
		if (primes.size() > 1){   //若primes.size() < 1，在最小值就是min_value，不必再比较。
			for (int j = 1; j < primes.size(); j++){
				res[i] = min(min_value, res[index[j]] * primes[j]);    //res存储符合条件的最小值，使得存储是有序的， 这样比较有利于取第n个值。
				if (min_value > res[index[j]] * primes[j]){
					min_value = res[index[j]] * primes[j];
				}
			}
		}
		else{
			res[i] = min_value;
		}
		
		for (int j = 0; j < primes.size(); j++){
			if (res[i] == res[index[j]] * primes[j])  index[j] ++;    // 更新index[j]，即primes[j]乘以了多少次
		}
	}
	return res[n - 1];
}

int main(){
	int n = 2;
	vector<int> primes = { 2 };
	int result = nthSuperUglyNumber(n, primes);
	cout << result << endl;
	return 0;
}