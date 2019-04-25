# include <iostream>
using namespace std;

//超时

int a[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { -1, 0, -1 } };
int counter = 0;

//数字允许重复
void dfs(int x, int y, int s, int N){ 
	int next[8][2] = {
		{-1, -2},   //左上1
		{-2, -1},   //左上2
		{1, -2},    //左上3
		{2, -1},    //左上4
		{-2, 1},    //左下5
		{-1, 2},    //左下6
		{1, 2},     //左下7
		{2, 1}      //左下8
	};

	int tx, ty;

	if (s == N){
		counter++;
		return;
	}
	for (int k = 0; k < 8; k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx < 0 || tx > 3 || ty < 0 || ty > 2 || (tx == 3 && ty == 0) || (tx == 3 && ty == 2)){
			continue;
		}
		dfs(tx, ty, s + 1, N);
	}
}


int knightDialer(int N) {
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (a[i][j] != -1){
				dfs(i, j, 1, N);
			}
		}
	}
	return counter % (1000000000 + 7);
}

int main(){
	counter = knightDialer(4);
	cout << counter << endl;
	return 0;
}

