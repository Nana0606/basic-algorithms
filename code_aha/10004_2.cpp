#include <iostream>
using namespace std;

void swap(int &a, int & b){
	int temp = a;
	a = b;
	b = temp;
}

int* quickSort(int p[], int left, int right){
	int i = left, j = right;
	int temp = p[left];    //枢纽
	if (i > j)
		return p;
	while (i < j){
		while ((p[j] >= temp) && (i < j))
			j--;
		while ((p[i] <= temp) && (i < j))
			i++;
		if (i < j){
			swap(p[i], p[j]);   //不需要将i和j的位置移动的原因是，在p[i]和p[j]交换位置之后，已经不满足while条件，所以j--和i++肯定会执行，除非i ==j了
		}
	} //end while ,i==j
	//枢纽和i==j对应的值交换
	p[left] = p[i];
	p[i] = temp;
	quickSort(p, left, i - 1);
	quickSort(p, j + 1, right);
	return p;
}


/*
思路是：先排序，再在排序的元素中去重，即如果当前元素和前面的元素相同，则不输出
*/

int main(){
	int N; //N表示输入数据的个数
	cin >> N;
	int *p = new int[N];
	for (int i = 0; i < N; i++){
		cin >> p[i];
	}
	p = quickSort(p, 0, N - 1);
	int count = 1;  //第一个数字肯定不重复
	for (int i = 0; i < N - 1; i++){
		if (p[i] != p[i + 1])  count++;   //当前元素和之前一个元素不相同
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