# include <iostream>
using namespace std;

struct note{
	int x;   //横坐标
	int y;   //纵坐标
};

int main(){
	struct note que[2501];
	int head, tail;
	int startx, starty, tx, ty;
	int sum = 0;

	int a[51][51];
	int book[51][51] = { 0 };

	int next[4][2] = {
		{0, 1},  //向右走
		{1, 0},  //向下走
		{0, -1}, //向左走
		{-1, 0}  //向上走
	};

	int n = 10, m = 10;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	cin >> startx >> starty;

	head = 1;
	tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;  //起始点已经访问过
	sum = 1;
	
	while (head < tail){
		for (int i = 0; i < 4; i++){
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];
			if (tx < 1 || tx > n || ty < 1 || ty > m){
				continue;
			}
			if (a[tx][ty] > 0 && book[tx][ty] == 0){
				sum++;
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;
	}
	cout << sum << endl;
}