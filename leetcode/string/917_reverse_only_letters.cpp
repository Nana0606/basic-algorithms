# include <iostream>
# include <string>
using namespace std;

//AC��˼�룺���ڲ�����ĸ��Ԫ�أ����Ų�������������ĸ��Ԫ�أ�ǰ��ĺͺ���Ľ��н���
string reverseOnlyLetters(string S) {
	int left = 0;
	int right = S.length() - 1;
	while (left < right){
		//���ж���������Ԫ�أ���Ҫ��κ��ƣ�����ʹ��while������ע��ʹ��while��ʱ����Ҫ��ֹleft��right�±곬����Χ��
		while (!((S[left] >= 'a' && S[left] <= 'z') || (S[left] >= 'A' && S[left] <= 'Z')) && left < right){
			left++;
		}
		while (!((S[right] >= 'a' && S[right] <= 'z') || (S[right] >= 'A' && S[right] <= 'Z')) && left < right){
			right--;
		}
		if (left < right){
			//S[left]��S[right]������ĸ
			char temp = S[left];
			S[left] = S[right];
			S[right] = temp;
			left++;
			right--;
		}
	}
	return S;
}

int main(){
	string S = "7_28]";
	string res = reverseOnlyLetters(S);
	cout << res << endl;
	return 0;
}