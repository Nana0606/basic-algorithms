# include<iostream>
# include <string>
# include <sstream>
# include <vector>
using namespace std;

//主要思想：因为1~10^9中就只有2^0、2^1、2^2、...、2^31是2的幂，因此只需要比较这些值是否和N中所有数字出现的个数一样即可。（这里使用的是哈希值的比比较方法）

//作用：获取所求数字的哈希码
long counter(int N){
	long res = 0;
	for (; N; N /= 10){
		res += pow(10, N % 10);  //如4出现2次，5出现1次，2出现1次，则哈希值是10^4+10^4+10^5+10^2
	}
	return res;
}

//寻找2^0~2^32的值，若counter(N)返回的结果和某一个值相等，则返回true，否则返回false
bool reorderedPowerOf2(int N) {
	long data = counter(N);
	for (int i = 0; i < 32; i++){
		if (counter(pow(2, i)) == data) return true;
	}
	return false;
}

int main(){
	int N = 125;
	bool res = reorderedPowerOf2(N);
	cout << res << endl;
	return 0;
}