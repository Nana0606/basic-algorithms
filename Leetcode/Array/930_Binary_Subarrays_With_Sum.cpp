# include <iostream>
# include <vector>
using namespace std;

int numSubarraysWithSum(vector<int>& A, int S) {
	int res = 0;
	for (int i = 0; i < int(A.size())-S+1; i++){   //注意，这边如果最后的元素数小于S，就不需要循环判断了。
		int count = 0;
		for (int j = i; j < int(A.size()); j++){
			count += A[j];
			if (count == S) res += 1;
			else if (count > S) break;  //加个else可以减少时间
		}
	}
	return res;
}

int main(){
	vector<int> A = { 1, 0, 1, 0, 1 };
	int S = 2;
	int res = numSubarraysWithSum(A, S);
	cout << res << endl;
	return 0;
}