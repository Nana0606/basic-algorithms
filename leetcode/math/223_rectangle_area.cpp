# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//思路：先将所有的求出，对于不overlap的先算着，然后计算overlap，这部分不要使用枚举法，容易错，使用排序后，可以画图查看overlap计算方式。

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int total = (C - A)*(D - B) + (G - E)*(H - F);
	if (E > C || G < A || D < F || H < B) return total;

	vector<int> x;
	vector<int> y;
	x.push_back(A);
	x.push_back(C);
	x.push_back(E);
	x.push_back(G);
	y.push_back(B);
	y.push_back(D);
	y.push_back(F);
	y.push_back(H);

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	 
	int overlap = (x[2] - x[1]) * (y[2] - y[1]);     //通过画图可以看出
	return total - overlap;
}

int main(){
	int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	int result = computeArea(A, B, C, D, E, F, G, H);
	cout << result << endl;
	return 0;
}