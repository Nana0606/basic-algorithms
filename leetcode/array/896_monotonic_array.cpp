# include <iostream>
# include <vector>
using namespace std;

//AC,主要思想是先判断是否是升序，如果不是，再判断是否降序
bool isMonotonic(vector<int>& A) {
	int i = A.size() - 1;
	//升序
	while (i >= 1 && (A[i]-A[i-1]>=0)){
		i--;
	}
	if (i == 0) return true;
	else{
		i = A.size() - 1;
		//降序
		while (i >= 1 && (A[i] - A[i - 1] <= 0)){
			i--;
		}
		if (i == 0) return true;
	}
	return false;
}

int main(){
	vector<int> A = { 6,5,4,4 };
	bool res = isMonotonic(A);
	cout << res << endl;
	return 0;
}