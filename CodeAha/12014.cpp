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
	if ((i == str.size()) && (mystack.empty())){  //若最后匹配完成并且匹配成功
		cout << "YES" << endl;
	}
	return 0;
}