# include <iostream>
# include <string>
# include <vector>
using namespace std;

//��strת����һ�����飬����洢ÿ���ַ����ֵĴ�����
int* count(string s){
	cout << s << endl;
	int *count_res = new int[26];
	for (int i = 0; i < 26; i++){
		count_res[i] = 0;
	}
	for (int i = 0; i < int(s.size()); i++){
		count_res[s[i] - 'a'] += 1;
	}
	return count_res;
}


vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
	vector<string> res;  //�洢����ļ�
	for (int i = 0; i < int(A.size()); i++){
		int *parent = count(A[i]);
		for (int i = 0; i < 26; i++){
			cout << parent[i] << " ";
		}
		cout << endl;
		int j = 0;
		for (j = 0; j < int(B.size()); j++){
			cout << " ��ǰ����ģ���" << B[j] << endl;
			int * child = count(B[j]);
			int k = 0;
			for (k = 0; k < 26; k++){
				if (child[k] > parent[k]){
					cout << B[j] << " " << k << endl;
					break;   //������ֹ��ѭ��
				}
			}
			cout << "k===" << k << endl;
			if (k < 26) break;  //������ֹ��ѭ��
			delete[] child;
		}
		if (j == int(B.size())) res.push_back(A[i]);
		delete[] parent;
	}
	return res;
}

int main(){
	vector<string> A = { "amazon", "apple", "facebook", "google", "leetcode" };
	vector<string> B = { "e", "oo" };
	vector<string> res = wordSubsets(A, B);
	cout << "***********************8" << endl;
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	return 0;
}

