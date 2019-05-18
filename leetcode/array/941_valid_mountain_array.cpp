# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int separate = 0, i = 0, j = 0;
		for (i = 0; i < int(A.size()) - 1; i++){
			if (A[i] == A[i + 1]) return false;
			else if (A[i] > A[i + 1]){
				separate = i;
				break;
			}
		}
		//��i�ǵ�һ�����������һ����Ҳ����
		if (i == int(A.size()) - 1 || i == 0)
			return false;
		else{  //���ǵ�һ��Ҳ�������һ��
			for (j = separate; j < int(A.size()) - 1; j++){
				if (A[j] <= A[j + 1]) return false;
			}
			if (j == int(A.size()) - 1){
				return true;
			}
		}
		return false;
	}
};


int main(){
	vector<int> A = { 2, 1};
	Solution solution;
	bool res = solution.validMountainArray(A);
	cout << res << endl;
	return 0;
}