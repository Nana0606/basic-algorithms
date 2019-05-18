# include <iostream>
# include <vector>
using namespace std;

//思想：使用2个vector，一个记录偶数，一个记录奇数，然后再将其放入result的结果中
vector<int> sortArrayByParityII(vector<int>& A) {
	vector<int> odd;
	vector<int> even;
	vector<int> res;
	for (int i = 0; i < A.size(); i++){
		if (A[i] % 2 == 0) even.push_back(A[i]);
		else odd.push_back(A[i]);
	}
	for (int i = 0; i < even.size(); i++){
		res.push_back(even[i]);
		res.push_back(odd[i]);
	}
	return res;
}

int main(){
	vector<int> A = { 4, 2, 5, 7 };
	vector<int> res = sortArrayByParityII(A);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	return 0;
}