# include <iostream>
using namespace std;

int a[10], book[10], total = 0;

//��ֻ��1~9��9����
void dfs(int step){
	int i;
	if (step == 10){
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9]){
			total++;
			cout << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] <<" " << a[6] << " " << a[7] <<" "<< a[8] << " "<< a[9] << endl;
		}
		return;
	}

	//����˳��ȡ��
	for (i = 1; i <= 9; i++){
		if (book[i] == 0){
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}

int main(){
	dfs(1);
	cout << total / 2 << endl;  // a+b=c��b+a=c��һ�����ʵ�
	return 0;
}