# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
	int len1 = word1.length(), len2 = word2.length();

	// dp数组初始化
	int **p = new int*[len1 + 1];
	for (int i = 0; i < len1 + 1; i++){
		p[i] = new int[len2 + 1];
		for (int j = 0; j < len2 + 1; j++){
			p[i][j] = 0;
		}
	}
	 
	// 边界值：d[i][0] = i, d[0][j] = j
	for (int i = 0; i < len1 + 1; i++){
		p[i][0] = i;
	}
	for (int j = 0; j < len2 + 1; j++){
		p[0][j] = j;
	}

	//算法
	for (int i = 1; i < len1 + 1; i++)
		for (int j = 1; j < len2 + 1; j++){
			// p[0][0]表示word1和word2都是空串，若都有一个元素，则是p[1][1]
			if (word1[i-1] == word2[j-1])  p[i][j] = p[i - 1][j - 1];
			else{
				/*
				若需要删除一个元素，则p[i][j] = p[i][j-1] + 1;
				若需要添加一个元素，则p[i][j] = p[i-1][j] + 1;
				若需要替换一个元素，则p[i][j] = p[i-1][j-1] + 1；
				*/
				p[i][j] = min(p[i][j - 1] + 1, min(p[i - 1][j] + 1, p[i - 1][j - 1] + 1));
			}
		}
	return p[len1][len2];
}

int main(){
	string word1 = "b", word2 = "";
	int res = minDistance(word1, word2);
	cout << res << endl;
	return 0;
}
