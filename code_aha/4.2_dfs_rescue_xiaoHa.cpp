# include <iostream>
using namespace std;

int a[51][51], book[51][51];
int x, y, step; //当前坐标x、y和步骤step
int p, q;
int min = INT_MAX; 
int n = 5, m = 4;   //n表示行数，m表示列数

void dfs(int x, int y, int step){
	int next[4][2] = {
		{0, 1 },  //向右走
		{1, 0},    //向下走
		{0, -1},   //向左走
		{-1, 0}    //向上走
	};

	if (x == p && y == q){   //若已经找到小哈的位置
		if (min > step) {
			min = step;
		}
		return;
	}

	int tx, ty;

	for (int i = 0; i < 4; i++){
		tx = x + next[i][0];
		ty = y + next[i][1];

		//判断是否越界
		if (tx < 1 || tx > n || ty<1 || ty>m)
			continue;
		//判断该点是否在障碍物或者已经在路径中
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
	cout << "请输入5行4列的数据" << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	int startx = 1, starty = 1;
	book[startx][starty] = 1;   //第一个起点已经走过，标记出来，防止再次经过
	dfs(startx, starty, 0);
	cout << min << endl;
	return 0;
}