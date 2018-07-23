# include <iostream>
using namespace std;

int main(){
	int N; //N表示n个随机数
	cin >> N;
	int p[1001];
	//数据初始化
	for (int i = 0; i < 1001; i++){
		p[i] = 0;
	}
	int value; // 用于存储输入的元素
	int count = 0; //用于记录不重复数据的个数
	for (int i = 0; i < N; i++){
		cin >> value;
		if (p[value] == 0) count++;
		p[value] = 1;
	}
	cout << count << endl;
	for (int i = 0; i < 1001; i++){
		if (p[i] == 1){
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}