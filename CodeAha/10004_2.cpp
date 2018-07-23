#include <iostream>
using namespace std;

void swap(int &a, int & b){
	int temp = a;
	a = b;
	b = temp;
}

int* quick_sort(int p[], int left, int right){
	int i = left, j = right;
	int temp = p[left];    //��Ŧ
	if (i > j)
		return p;
	while (i < j){
		while ((p[j] >= temp) && (i < j))
			j--;
		while ((p[i] <= temp) && (i < j))
			i++;
		if (i < j){
			swap(p[i], p[j]);   //����Ҫ��i��j��λ���ƶ���ԭ���ǣ���p[i]��p[j]����λ��֮���Ѿ�������while����������j--��i++�϶���ִ�У�����i ==j��
		}
	} //end while ,i==j
	//��Ŧ��i==j��Ӧ��ֵ����
	p[left] = p[i];
	p[i] = temp;
	quick_sort(p, left, i - 1);
	quick_sort(p, j + 1, right);
	return p;
}


/*
˼·�ǣ����������������Ԫ����ȥ�أ��������ǰԪ�غ�ǰ���Ԫ����ͬ�������
*/

int main(){
	int N; //N��ʾ�������ݵĸ���
	cin >> N;
	int *p = new int[N];
	for (int i = 0; i < N; i++){
		cin >> p[i];
	}
	p = quick_sort(p, 0, N - 1);
	int count = 1;  //��һ�����ֿ϶����ظ�
	for (int i = 0; i < N - 1; i++){
		if (p[i] != p[i + 1])  count++;   //��ǰԪ�غ�֮ǰһ��Ԫ�ز���ͬ
	}
	cout << count << endl;
	cout << p[0] << " ";
	for (int i = 0; i < N - 1; i++){
		if (p[i] != p[i + 1]){
			cout << p[i + 1] << " ";
		}
	}
	cout << endl;
	return 0;
}