# include <iostream>
# include <cstring>
# include <string>
using namespace std;

int main(){
	char s[101];
	string input;
	cin >> input;
	const char *a = input.c_str();    //stringת��Ϊchar*
	int len = strlen(a);
	int mid = (len + 1) / 2 - 1;
	int top = 0;
	if (len % 2 == 0){
		//�洢����
		for (int i = 0; i < mid + 1; i++){
			s[top++] = a[i];
		}
		//�Ƚ��Ƿ����
		for (int i = mid + 1; i < len; i++){
			if (a[i] == s[--top]){}
			else{
				cout << "NO" << endl;
				break;
			}
		}
		if (top == 0){
			cout << "YES" << endl;
		}
	}
	else{
		//�洢����
		for (int i = 0; i < mid; i++){
			s[top++] = a[i];
		}
		//�Ƚ��Ƿ����
		for (int i = mid + 1; i < len; i++){
			if (a[i] == s[--top]){}
			else{
				cout << "NO" << endl;
				break;
			}
		}
		if (top == 0){
			cout << "YES" << endl;
		}
	}
	return 0;
}