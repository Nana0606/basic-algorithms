#include<iostream>
using namespace std;

int main(){
	int L;    //马路的长度
	int M; // 区域的个数
	int p1 = 0, p2 = 0;
	cin >> L  >> M;
	int *p = new int[L+1];
	for (int i = 0; i <= L; i++){
		p[i] = 1;
	}
	for (int i = 0; i < M; i++){
		cin >> p1 >> p2;
		for (int p0 = p1; p0 <= p2; p0++){
			p[p0] = 0;
		}
	}
	int count = 0;
	for (int i = 0; i <= L; i++){
		if (p[i] == 1)
			count++;
	}
	cout << count << endl;
	return 0;
}