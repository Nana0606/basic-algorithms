# include <iostream>
# include <vector>
using namespace std;

//注意题目：若输入的是4个字符，则输出的是0~4共5个数字
class Solution {
public:
	vector<int> diStringMatch(string S) {
		int left = count(S.begin(), S.end(), 'D'), right = left;
		vector<int> res = { left };
		for (char c : S){
			res.push_back((c == 'I' ? ++right : --left));
		}
		return res;
	}
};

int main(){
	Solution solution;
	string S = "IDDIDD";
	vector<int> res = solution.diStringMatch(S);
	for (int i = 0; i < int(res.size()); i++){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}