# include <iostream>
# include <stack>
using namespace std;

//思路，使用2个栈，第一个存左括号，第二个存右括号
int minAddToMakeValid(string S) {
	stack<char> left;
	stack<char> right;
	for (int i = 0; i < S.length(); i++){
		if (S[i] == '('){
			left.push(S[i]);
		}
		if (S[i] == ')'){
			if (left.size() > 0){   //若是左括号有内容，则先pop一个左括号
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