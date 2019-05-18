# include <iostream>
# include <vector>
using namespace std;

// AC，easy，主要行列的维度可能不一样
vector<vector<int>> transpose(vector<vector<int>>& A) {
	vector<vector<int> > res;
	vector<int> temp(int(A.size()));
	res.resize(int(A[0].size()), temp);
	for (int i = 0; i < int(A.size()); i++){
		for (int j = 0; j < int(A[0].size()); j++){
			res[j][i] = A[i][j];
		}
	}
	return res;
}

int main(){
	vector<vector<int> > A = { { 1, 2, 3 }, { 4, 5, 6 } };
	vector<vector<int>> res = transpose(A);
	for (int i = 0; i < int(res.size()); i++){
		for (int j = 0; j<int(res[0].size()); j++){
			cout << res[i][j] << " ";
		}
	}
	cout << endl;
	return 0;
}