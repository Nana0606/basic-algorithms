# include <iostream>
using namespace std;

int a[51][51], book[51][51];
int x, y, step; //��ǰ����x��y�Ͳ���step
int p, q;
int min = INT_MAX; 
int n = 5, m = 4;   //n��ʾ������m��ʾ����

void dfs(int x, int y, int step){
	int next[4][2] = {
		{0, 1 },  //������
		{1, 0},    //������
		{0, -1},   //������
		{-1, 0}    //������
	};

	if (x == p && y == q){   //���Ѿ��ҵ�С����λ��
		if (min > step) {
			min = step;
		}
		return;
	}

	int tx, ty;

	for (int i = 0; i < 4; i++){
		tx = x + next[i][0];
		ty = y + next[i][1];

		//�ж��Ƿ�Խ��
		if (tx < 1 || tx > n || ty<1 || ty>m)
			continue;
		//�жϸõ��Ƿ����ϰ�������Ѿ���·����
		if (a[tx][ty] == 0 && book[tx][ty] == 0){
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}

int main(){
	p = 4, q = 3;
	cout << "������5��4�е�����" << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	int startx = 1, starty = 1;
	book[startx][starty] = 1;   //��һ������Ѿ��߹�����ǳ�������ֹ�ٴξ���
	dfs(startx, starty, 0);
	cout << min << endl;
	return 0;
}