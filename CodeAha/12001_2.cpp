# include <iostream>
using namespace std;

int* quick_sort(int p[], int left, int right){
	int i = left, j = right;
	int temp = p[left];  //����ߵ�Ԫ�أ�����һ����Ŧ��
	if (i > j)
		return p;
	while (i < j){
		while ((p[j]>=temp) && (i < j))
			j--;   //һ��Ҫ�ȴ�j��ʼ���������ұ߿�ʼ
		while ((p[i] <= temp) && (i < j))
			i++;
		if (i < j){
			swap(p[i], p[j]);  //����ҵ�һ����ģ��ұ��ҵ�һ��С�ģ��滻
		}
	}// end while, i=j
	//���潫i=jʱ��Ԫ��ֵ����Ŧֵ����
	p[left] = p[i];
	p[i] = temp;
	quick_sort(p, left, i - 1);
	quick_sort(p, j + 1, right);
	return p;
}

int main(){
	int n; //n��ʾ�������ݵĸ���
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}
	int count = 1;    //��һ������һ���ǲ��ظ��ġ�
	p = quick_sort(p, 0, n - 1);
	for (int i = 0; i < n-1; i++){
		if (p[i] != p[i + 1]){     //˵����ǰֵ��ǰһ�����ݲ��ظ�
			count++;    //ͳ�Ʋ��ظ�����Ŀ
		}
	}
	cout << count << endl;
	cout << p[0] << " ";    //�����һ��ֵ
	for (int i = 0; i < n - 1; i++){    //�����ظ����������
		if (p[i] != p[i + 1]){
			cout << p[i + 1] << " ";
		}
	}
	cout << endl;
	return 0;
}