# include <iostream>
# include <sstream>
# include <string>
# include <vector>
#include <unordered_map>
using namespace std;

//主要思想，问题可以转化为在2个字符串中，无论各自出现了多少次，最终只要出现了1次的字符串，输出
//注意下实现，
vector<string> uncommonFromSentences(string A, string B) {
	vector<string> res;
	unordered_map<string, int> counter;
	istringstream iss(A + " " + B);  //可以自动以空格为分隔符
	while (iss >> A){
		counter[A]++;    //map
	}
	for (auto w : counter){
		if (w.second == 1) res.push_back(w.first);
	}
	return res;
}

int main(){
	string A = "this apple is sweet";
	string B = "this apple is sour";
	vector<string> res;
	res = uncommonFromSentences(A, B);
	for (int i = 0; i<int(res.size()); i++){
		cout << res[i] << endl;
	}
	return 0;
}
