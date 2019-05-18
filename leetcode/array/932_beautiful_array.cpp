# include <iostream>
# include<vector>
# include <algorithm>
using namespace std;

//方法一：全排列，然后求每一个排列是否满足要求，复杂度太高，时间超时
/*
bool isBeautiful(int *myints, int N){
	for (int i = 0; i < N - 2; i++){
		for (int j = i + 2; j < N; j++){
			if ((myints[i] + myints[j]) % 2 == 0) {
				int temp = (myints[i] + myints[j]) / 2;
				for (int k = i + 1; k < j; k++){
					if (myints[k] == temp) return false;
				}
			}
		}
	}
	return true;
}

vector<int> beautifulArray(int N) {
	int *myints = new int[N];
	for (int i = 0; i < N; i++){
		myints[i] = i + 1;
	}
	do{
		//现在已经有一个序列，需要判断此序列是否是一个beautiful序列
		bool res = isBeautiful(myints, N);
		if (res == true){
			vector<int> temp(myints, myints + N);
			return temp;
		}
	} while (next_permutation(myints, myints + N));
	delete[] myints;
}
*/

//利用了分治的思想
vector<int> beautifulArray(int N) {
	vector<int> res = { 1 };
	while (res.size() < N){
		vector<int> temp;
		for (int i : res){
			if (i * 2 - 1 <= N) temp.push_back(i * 2 - 1);
		}
		for (int i : res){
			if (i * 2 <= N) temp.push_back(i * 2);
		}
		res = temp;
	}
	return res;
}

int main () {
	int N = 100;
	vector<int> res = beautifulArray(N);
	for (int i = 0; i < N; i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}