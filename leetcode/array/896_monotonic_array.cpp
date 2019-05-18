# include <iostream>
# include <vector>
using namespace std;

//AC,��Ҫ˼�������ж��Ƿ�������������ǣ����ж��Ƿ���
bool isMonotonic(vector<int>& A) {
	int i = A.size() - 1;
	//����
	while (i >= 1 && (A[i]-A[i-1]>=0)){
		i--;
	}
	if (i == 0) return true;
	else{
		i = A.size() - 1;
		//����
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