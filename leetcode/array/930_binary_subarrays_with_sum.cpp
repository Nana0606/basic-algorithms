# include <iostream>
# include <vector>
using namespace std;

int numSubarraysWithSum(vector<int>& A, int S) {
	int res = 0;
	for (int i = 0; i < int(A.size())-S+1; i++){   //ע�⣬����������Ԫ����С��S���Ͳ���Ҫѭ���ж��ˡ�
		int count = 0;
		for (int j = i; j < int(A.size()); j++){
			count += A[j];
			if (count == S) res += 1;
			else if (count > S) break;  //�Ӹ�else���Լ���ʱ��
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