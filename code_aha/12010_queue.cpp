# include <iostream>
using namespace std;
int p[200000];     //�����鳤�ȱȽϴ�ʱ���������ȫ�ֱ�����λ�ã���Ϊȫ�ֱ���ʹ�õ��Ƕѣ�����main��ʹ�õ���չ����ʹ����ǳ�����

int main(){
	cin.sync_with_stdio(false);
	int n;  //��ʾQ����nλ
	cin >> n;
	
	int head = 0;
	int tail = n;
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}

	while (head < tail){
		cout << p[head] << " ";  //�����������
		head++;

		p[tail] = p[head];   //ż�����Ƶ�����
		head++;
		tail++;
	}
	cout << endl;
	return 0;
}