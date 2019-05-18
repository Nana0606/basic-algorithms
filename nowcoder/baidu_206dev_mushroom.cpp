# include <iostream>
using namespace std;
 
double dfs(int x, int y, int count_is, int total, int N, int M, int **p, int **book){
	int next[4][2] = {
		{ 0, 1 },  //向上走
		{ 0, -1 }, //向下走
		{ 1, 0 }, //向右走
		{ -1, 0 }  //向左走
	};
	int tx, ty;
	if (x == M - 1 && y == N - 1){
		total++;
	}
	for (int k = 0; k <= 3; k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx < 0 || tx > M - 1 || ty < 0 || ty > N - 1)
			continue;
		if (p[tx][ty] == 1 && book[tx][ty] == 0){
			count_is++;
			book[tx][ty] == 1;
			dfs(tx, ty, count_is, total, N, M, p, book);
			book[tx][ty] == 0;
		}
	}
	return count_is / total;
}

int main(){
	int N, M, K;
	int x, y;
	while (cin >> N >> M >> K){
		int **p, **book;
		p = new int*[N];
		book = new int*[N];
		for (int i = 0; i < N; i++){
			p[i] = new int[M];
			book[i] = new int[M];
			for (int j = 0; j < M; j++){
				p[i][j] = 0;
				book[i][j] = 0;
			}
		}
		while (K-- > 0){
			cin >> x >> y;
			p[x - 1][y - 1] = 1;
		}
	
		int count_is = 0, total = 0;
		book[0][0] = 1;
		//判断是否到达
		double ratio = dfs(0, 0, count_is, total, N, M, p, book);
		cout << ratio << endl;
	}
	return 0;
}