# include <iostream>
using namespace std;

struct note{
	int x;  //横坐标
	int y;  //纵坐标
	int f;  //父亲在队列中的编号，本题不需要输出编号，可以不需要
	int s;  //步数
};

int main(){
	struct note que[2501];

	int a[51][51] = { 0 }, book[51][51] = { 0 };

	//定义一个用于表示走的方向的数组
	int next[4][2] = {
		{0, 1}, //向右走
		{1, 0}, //向下走
		{0, -1}, //向左走
		{-1, 0}  //向上走
	};

	int n = 5, m = 4, p = 4, q = 3; //n表示行数，m表示列数
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

	flag = 0; //用来标记是否到达目标点，0表示暂时还没有到达，1表示已经到达

	while (head < tail){
		for (int i = 0; i < 4; i++){
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];

			//判断是否越界
			if (tx < 1 || tx > n || ty < 1 || ty > m){
				continue;
			}

			//和深度搜索不同，不需要将book数组还原
			if (a[tx][ty] == 0 && book[tx][ty] == 0){
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}

			if (tx == p && ty == q){  //到达停止点
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