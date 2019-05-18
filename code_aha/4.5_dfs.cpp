# include <iostream>
using namespace std;

int a[51][51];
int book[51][51];
int n, m, sum;

void dfs(int x, int y){
	int next[4][2] = {
		{ 0, 1 }, //向右走
		{ 1, 0 }, //向下走
		{ 0, -1 }, //向左走
		{-1, 0} //向上走
	};

	int tx, ty;
	for (int i = 0; i < 4; i++){
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (tx < 1 || tx > n || ty < 1 || ty > m){
			continue;
		}
		if (a[tx][ty] > 0 && book[tx][ty] == 0){
			sum++;
			book[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
}

int main(){
	n = 10;
	m = 10;
	int startx, starty;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	cin >> startx >> starty;
	book[startx][starty] = 1;
	sum = 1;
	dfs(startx, starty);
	cout << sum << endl;
	return 0;
}