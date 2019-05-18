# include <iostream>
using namespace std;

//最常规做法
/*
int addDigits(int num) {
	int total_sum = num;   //表示最外层的sum，控制是否小于10的，小于10即可停止
	while (total_sum > 9){
		int sum = 0;  //sum，控制针对上一不满足停止的total_sum，计算其各位相加之和
		while (total_sum > 0){
			sum += total_sum % 10;
			total_sum /= 10;
		}
		total_sum = sum;
	}	
	return total_sum;
}
*/

//方法二：数跟问题
//公式：dr(n)=1+((n-1) mod 9)
int addDigits(int num) {
	return 1 + (num - 1) % 9;
}

int main(){
	int num = 139;
	int res = addDigits(num);
	cout << res << endl;
	return 0;
}