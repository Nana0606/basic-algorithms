#include <iostream>
using namespace std;

struct milk{
	int pi;     //ţ�̵���
	int ai;     //ţ������
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
	int N, M;      //N��ʾ��Ҫ��ţ��������M��ʾ�ṩţ�̵���ũ����
	cin >> N >> M;
	milk* p = new milk[M];
	for (int i = 0; i < M; i++){
		cin >> p[i].pi >> p[i].ai;
	}
	p = quick_sort(p, 0, M - 1);
	int total_money = 0;
	for (int index = 0; index < M; index++){
		if (N >= p[index].ai){    //˵��index����ũ����ȫ����Ҫ
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