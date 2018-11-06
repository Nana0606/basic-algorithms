# include <iostream>
using namespace std;

struct note{
	int x;  //������
	int y;  //������
	int f;  //�����ڶ����еı�ţ����ⲻ��Ҫ�����ţ����Բ���Ҫ
	int s;  //����
};

int main(){
	struct note que[2501];

	int a[51][51] = { 0 }, book[51][51] = { 0 };

	//����һ�����ڱ�ʾ�ߵķ��������
	int next[4][2] = {
		{0, 1}, //������
		{1, 0}, //������
		{0, -1}, //������
		{-1, 0}  //������
	};

	int n = 5, m = 4, p = 4, q = 3; //n��ʾ������m��ʾ����
	int startx = 1, starty = 1, flag, tx, ty;
	int head;
	int tail;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}

	head = 1;
	tail = 1;

	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;

	flag = 0; //��������Ƿ񵽴�Ŀ��㣬0��ʾ��ʱ��û�е��1��ʾ�Ѿ�����

	while (head < tail){
		for (int i = 0; i < 4; i++){
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];

			//�ж��Ƿ�Խ��
			if (tx < 1 || tx > n || ty < 1 || ty > m){
				continue;
			}

			//�����������ͬ������Ҫ��book���黹ԭ
			if (a[tx][ty] == 0 && book[tx][ty] == 0){
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}

			if (tx == p && ty == q){  //����ֹͣ��
				flag = 1;
				break; 
			}
		}
		if (flag == 1)
			break;
		head++;
	}

	cout << que[tail - 1].s << endl;

	return 0;
}