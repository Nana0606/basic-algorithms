# include <iostream>
using namespace std;
int p[200000];     //当数组长度比较大时，将其放在全局变量的位置，因为全局变量使用的是堆，而在main中使用的是展，会使程序非常慢。

int main(){
	cin.sync_with_stdio(false);
	int n;  //表示Q号有n位
	cin >> n;
	
	int head = 0;
	int tail = n;
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}

	while (head < tail){
		cout << p[head] << " ";  //奇数的先输出
		head++;

		p[tail] = p[head];   //偶数的移到后面
		head++;
		tail++;
	}
	cout << endl;
	return 0;
}