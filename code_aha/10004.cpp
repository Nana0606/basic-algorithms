# include <iostream>
using namespace std;

int main(){
	int N; //N��ʾn�������
	cin >> N;
	int p[1001];
	//���ݳ�ʼ��
	for (int i = 0; i < 1001; i++){
		p[i] = 0;
	}
	int value; // ���ڴ洢�����Ԫ��
	int count = 0; //���ڼ�¼���ظ����ݵĸ���
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