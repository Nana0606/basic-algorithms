# include <iostream>
# include <stack>
# include <cstring>
# include <string>
using namespace std;

int main(){
	string s;
	cin >> s;     // 直接输入字符串需要添加头文件# include <string>
	const char* p= s.c_str();
	stack<char> mystack;
	int len = strlen(p);     //使用strlen需要添加头文件# include <cstring>
	int mid = (len+1) / 2  - 1;
	int end_index = mid;   //不包含end_index
	if (len % 2 == 0){
		//存储数据进入栈
		for (int i = 0; i < end_index + 1; ++i){
			mystack.push(p[i]);
		}
		int j = 0;
		//比较是否是回文序列
		for (j = end_index + 1; j < len; j++){
			if (p[j] == mystack.top()){
				mystack.pop();
			}
			else{
				cout << "NO" << endl;
				break;
			}
		}
		if (j == len){
			cout << "YES" << endl;
		}
	}
	else{
		//存储数据进入栈
		for (int i = 0; i < end_index; ++i){
			mystack.push(p[i]);
		}
		int k = 0;
		//比较是否是回文序列
		for (k = end_index + 1; k < len; k++){
			if (p[k] == mystack.top()){
				mystack.pop();
			}
			else{
				cout << "NO" << endl;
				break;
			}
		}
		if (k == len){
			cout << "YES" << endl;
		}
	}
	return 0;
}