# include <iostream>
# include <string>
using namespace std;


//AC,
//思路：从i=0到i=length()(注意：i=length说明需要考虑全部是0的情况)，这个i记录的是第一个1开始的位置，因为第一个1的位置已经确定，所以可以i下标之前都应该是0，i及i之后的位置都是1
//只需要替换i之前值为1的元素，和i及之后值为0的元素。
int minFlipsMonoIncr(string S){
	S += "1";
	int min = INT_MAX;
	//单独处理i=0的情况
	int count = 0;
	for (int k = 0; k < S.length(); k++){
		if (S[k] == '0'){ count++; }
	}
	if (min >= count) min = count;
	count = 0;
	for (int i = 1; i < S.length(); i++){
		for (int j = 0; j < i; j++){
			if (S[j] == '1') count++;
		}
		for (int j = i; j < S.length(); j++){
			if (S[j] == '0') count++;
		}
		if (min >= count) min = count;
		count = 0;
	}
	return min;
}

int main(){
	string s = "00011000";
	int res = minFlipsMonoIncr(s);
	cout << res << endl;
	return 0;
}