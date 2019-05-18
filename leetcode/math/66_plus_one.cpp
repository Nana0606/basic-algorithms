# include <iostream>
# include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {

	for (int i = digits.size()-1; i >= 0; i--){
		if (digits[i] == 9){
			digits[i] = 0;
		}
		else{
			digits[i] ++;
			return digits;    //��������������Լ�С������
		}
	}
	//�������ﻹû��return��˵����9999�������ͣ���Ҫ����һλ��Ϊ1�������һ��0
	digits[0] = 1;
	digits.push_back(0);
	return digits;
}


int main(){
	vector<int> digits = { 9, 9, 9 };
	vector<int> result = plusOne(digits);
	vector<int>::iterator it;
	for (it = result.begin(); it < result.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}