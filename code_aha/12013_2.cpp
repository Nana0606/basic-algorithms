# include <iostream>
# include <stack>
# include <cstring>
# include <string>
using namespace std;

int main(){
	string s;
	cin >> s;     // ֱ�������ַ�����Ҫ���ͷ�ļ�# include <string>
	const char* p= s.c_str();
	stack<char> mystack;
	int len = strlen(p);     //ʹ��strlen��Ҫ���ͷ�ļ�# include <cstring>
	int mid = (len+1) / 2  - 1;
	int end_index = mid;   //������end_index
	if (len % 2 == 0){
		//�洢���ݽ���ջ
		for (int i = 0; i < end_index + 1; ++i){
			mystack.push(p[i]);
		}
		int j = 0;
		//�Ƚ��Ƿ��ǻ�������
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
		//�洢���ݽ���ջ
		for (int i = 0; i < end_index; ++i){
			mystack.push(p[i]);
		}
		int k = 0;
		//�Ƚ��Ƿ��ǻ�������
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