# include <iostream>
using namespace std;

/**
//这一种方法时间超时
bool checkPerfectNumber(int num) {
	if (num <= 0) return false;
	int sum = 0;
	for (int i = 1; i <= num / 2; i++){
		if (num % i == 0){
			sum += i;
		}
	}
	if (num == sum) return true;
	else return false;
}
*/

//主要是对i和num/i可以同时加起来的改进
bool checkPerfectNumber(int num) {
	if (num <= 1) return false;
	int sum = 0;
	for (int i = 1; i <= sqrt(num); i++){
		if (num % i == 0){
			sum += i;
			if (i != 1 && i != sqrt(num)){
				sum += num / i;
			}
		}
	}
	if (num == sum) return true;
	else return false;
}


int main(){
	int num =1;
	bool result = checkPerfectNumber(num);
	cout << result << endl;
	return 0;
}