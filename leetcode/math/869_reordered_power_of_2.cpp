# include<iostream>
# include <string>
# include <sstream>
# include <vector>
using namespace std;

//��Ҫ˼�룺��Ϊ1~10^9�о�ֻ��2^0��2^1��2^2��...��2^31��2���ݣ����ֻ��Ҫ�Ƚ���Щֵ�Ƿ��N���������ֳ��ֵĸ���һ�����ɡ�������ʹ�õ��ǹ�ϣֵ�ıȱȽϷ�����

//���ã���ȡ�������ֵĹ�ϣ��
long counter(int N){
	long res = 0;
	for (; N; N /= 10){
		res += pow(10, N % 10);  //��4����2�Σ�5����1�Σ�2����1�Σ����ϣֵ��10^4+10^4+10^5+10^2
	}
	return res;
}

//Ѱ��2^0~2^32��ֵ����counter(N)���صĽ����ĳһ��ֵ��ȣ��򷵻�true�����򷵻�false
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