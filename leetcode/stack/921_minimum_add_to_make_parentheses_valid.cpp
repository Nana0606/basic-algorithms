# include <iostream>
# include <stack>
using namespace std;

//˼·��ʹ��2��ջ����һ���������ţ��ڶ�����������
int minAddToMakeValid(string S) {
	stack<char> left;
	stack<char> right;
	for (int i = 0; i < S.length(); i++){
		if (S[i] == '('){
			left.push(S[i]);
		}
		if (S[i] == ')'){
			if (left.size() > 0){   //���������������ݣ�����popһ��������
				left.pop();
			}
			else{
				right.push(')');
			}
		}
	}
	return left.size() + right.size();
}

int main(){
	string S = "()))((";
	int res = minAddToMakeValid(S);
	cout << res << endl;
	return 0;
}