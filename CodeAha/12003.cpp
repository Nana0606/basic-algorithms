#include <iostream>
using namespace std;

struct milk{
	int pi;     //牛奶单价
	int ai;     //牛奶数量
};

void swap(milk &p1, milk &p2){
	milk temp = p1;
	p1 = p2;
	p2 = temp;
}

milk* quick_sort(milk *p, int left, int right){
	int i = left, j = right;
	milk temp = p[left];
	if (i > j){
		return p;
	}
	while (i < j){
		while ((p[j].pi >= temp.pi) && (i < j))
			j--;
		while ((p[i].pi <= temp.pi) && (i < j))
			i++;
		if (i < j){
			swap(p[i], p[j]);
		}
	}
	p[left] = p[i];
	p[i] = temp;
	quick_sort(p, left, i - 1);
	quick_sort(p, i + 1, right);
	return p;
}


int main(){ 
	int N, M;      //N表示需要的牛奶总数，M表示提供牛奶的奶农个数
	cin >> N >> M;
	milk* p = new milk[M];
	for (int i = 0; i < M; i++){
		cin >> p[i].pi >> p[i].ai;
	}
	p = quick_sort(p, 0, M - 1);
	int total_money = 0;
	for (int index = 0; index < M; index++){
		if (N >= p[index].ai){    //说明index的奶农的奶全部都要
			total_money += p[index].pi * p[index].ai;
			N = N - p[index].ai;
		}
		else if ((N < p[index].ai) && (N >0)){
			total_money += N * p[index].pi;
			break;
		}
		else{
			break;
		}
	}
	cout << total_money << endl;
	return 0;
}