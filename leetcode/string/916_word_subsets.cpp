# include <iostream>
# include <string>
# include <vector>
using namespace std;

//将str转化成一个数组，数组存储每个字符出现的次数。
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
	vector<string> res;  //存储结果文件
	for (int i = 0; i < int(A.size()); i++){
		int *parent = count(A[i]);
		for (int i = 0; i < 26; i++){
			cout << parent[i] << " ";
		}
		cout << endl;
		int j = 0;
		for (j = 0; j < int(B.size()); j++){
			cout << " 当前处理的：：" << B[j] << endl;
			int * child = count(B[j]);
			int k = 0;
			for (k = 0; k < 26; k++){
				if (child[k] > parent[k]){
					cout << B[j] << " " << k << endl;
					break;   //负责终止内循环
				}
			}
			cout << "k===" << k << endl;
			if (k < 26) break;  //负责终止中循环
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

