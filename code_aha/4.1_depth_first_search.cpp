# include <iostream>
using namespace std;

int a[10], book[10], n;

void dfs(int step){
	int i;
	if (step == n + 1){   //���վ�ڵ�n+1��������ǰ��˵��ǰn��λ���Ѿ�ȷ��
		for (i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		return;    //һ��Ҫreturn��return֮�󷵻����һ�ε���dfs�ĵط�
	}

	for (i = 1; i <= n; i++){   //����1��2��3...��˳��ʼ����
		if (book[i] == 0){
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;  //���˿����ջ�
		}
	}
	return;
}

int main(){
	n = 4;
	dfs(1);
	return 0;
}