#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main(){
	stack<char> mystack;
	string str;
	cin >> str;
	int i = 0;
	map<char, char> inverse;     // inverse map
	inverse['('] = ')';
	inverse['{'] = '}';
	inverse['['] = ']';
	for (i = 0; i < str.size(); i++){
		if ((str[i] == '{') || (str[i] == '[') || (str[i] == '(')){
			mystack.push(str[i]);
		}
		else{
			if ((!mystack.empty()) && (str[i] == inverse[mystack.top()])){
				mystack.pop();
			}
			else{
				cout << "NO" << endl;
				break;
			}
		}
	}
	if ((i == str.size()) && (mystack.empty())){  //�����ƥ����ɲ���ƥ��ɹ�
		cout << "YES" << endl;
	}
	return 0;
}