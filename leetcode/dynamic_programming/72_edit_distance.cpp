# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
	int len1 = word1.length(), len2 = word2.length();

	// dp�����ʼ��
	int **p = new int*[len1 + 1];
	for (int i = 0; i < len1 + 1; i++){
		p[i] = new int[len2 + 1];
		for (int j = 0; j < len2 + 1; j++){
			p[i][j] = 0;
		}
	}
	 
	// �߽�ֵ��d[i][0] = i, d[0][j] = j
	for (int i = 0; i < len1 + 1; i++){
		p[i][0] = i;
	}
	for (int j = 0; j < len2 + 1; j++){
		p[0][j] = j;
	}

	//�㷨
	for (int i = 1; i < len1 + 1; i++)
		for (int j = 1; j < len2 + 1; j++){
			// p[0][0]��ʾword1��word2���ǿմ���������һ��Ԫ�أ�����p[1][1]
			if (word1[i-1] == word2[j-1])  p[i][j] = p[i - 1][j - 1];
			else{
				/*
				����Ҫɾ��һ��Ԫ�أ���p[i][j] = p[i][j-1] + 1;
				����Ҫ���һ��Ԫ�أ���p[i][j] = p[i-1][j] + 1;
				����Ҫ�滻һ��Ԫ�أ���p[i][j] = p[i-1][j-1] + 1��
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
