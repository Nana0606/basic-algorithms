# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

bool isUgly(int num) {
	if (num <= 0) return false;
	if (num == 1) return true;
	while (num != 1){
		if (num % 2 == 0){
			num /= 2;
		}
		else if (num % 3 == 0){
			num /= 3;
		}
		else if (num % 5 == 0){
			num /= 5;
		}
		else{
			return false;
		}
	}
	return true;
}

/**
// 最后一个case超时
int nthUglyNumber(int n) {
	int max_value = 1;
	if (n == 1)
		return max_value;
	int circle = 2;
	for (int i = 2; i <= n; i++){
		while (!isUgly(circle)){
			circle ++ ;
		}
		max_value = circle;
		circle ++;
	}
	return max_value;
}
*/

// AC
int nthUglyNumber(int n){
	if (n <= 0) return false;
	if (n == 1) return true;
	int t2 = 0, t3 = 0, t5 = 0;  //记录2的倍数、3的倍数和5的倍数
	vector<int> res(n);
	res[0] = 1;
	for (int i = 1; i < n; i++){
		res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
		//更新t2、t3和t5
		if (res[i] == res[t2] * 2)   t2++;
		if (res[i] == res[t3] * 3)   t3++;
		if (res[i] == res[t5] * 5)   t5++;
	}
	return res[n - 1];
}

int main(){
	int n = 10;
	int result = nthUglyNumber(n);
	cout << result << endl;
	return 0;
}