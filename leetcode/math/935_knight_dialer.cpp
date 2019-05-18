# include <iostream>
using namespace std;

//��ʱ

int a[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { -1, 0, -1 } };
int counter = 0;

//���������ظ�
void dfs(int x, int y, int s, int N){ 
	int next[8][2] = {
		{-1, -2},   //����1
		{-2, -1},   //����2
		{1, -2},    //����3
		{2, -1},    //����4
		{-2, 1},    //����5
		{-1, 2},    //����6
		{1, 2},     //����7
		{2, 1}      //����8
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

