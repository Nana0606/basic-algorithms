# include <iostream>
using namespace std;

int main(){
	int n; //表示有n个同学参与调查（n<=100）
	cin >> n;
	int value;  //value表示输入值
	int count = 0; //count表示买多少本书
	int p[1001];
	for (int i = 0; i < 1001; i++)
		p[i] = 0;
	for (int i = 0; i < n; ++i){
		cin >> value;
		if (p[value] == 0){
			count ++;
		}
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