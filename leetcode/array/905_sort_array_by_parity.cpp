# include<iostream>
# include <vector>
using namespace std;

//两面夹击
vector<int> sortArrayByParity(vector<int>& A) {
	int i = 0, j = int(A.size()) - 1;  //i记录偶数，j记录奇数
	while (i < j){
		while (A[i] % 2 == 0 && i<j){
			i++;
		}
		while (A[j] % 2 == 1&& i<j){
			j--;
		}
		if (i < j){
			//A[i]和A[j]交换
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	return A;
}

int main(){
	vector<int> A = { 2, 3, 4, 1 };
	vector<int> res;
	res = sortArrayByParity(A);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	return 0;
}