# include <iostream>
# include <vector>
using namespace std;

//ע����Ŀ�����������4���ַ������������0~4��5������
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