# include <iostream>
# include <vector>
using namespace std;

//˼�룺ʹ��2��vector��һ����¼ż����һ����¼������Ȼ���ٽ������result�Ľ����
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