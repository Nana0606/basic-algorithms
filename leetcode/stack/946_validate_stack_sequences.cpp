# include <iostream>
# include <vector>
# include <stack>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (int(pushed.size()) != (int)popped.size()){
			return false;
		}
		stack<int> a;
		int j = 0;
		for (int i = 0; i < int(pushed.size()); i++){
			a.push(pushed[i]);
			// ×¢Òâ×¢Òâ£º£º!(a.empty())
			while (!(a.empty()) && a.top() == popped[j] && j < (int)popped.size()){
				j++;
				a.pop();
			}
		}
		return a.empty() && (j == int(pushed.size()));
	}
};

int main(){
	vector<int> pushed = { 1, 2, 3, 4, 5 };
	vector<int> poped = { 4, 5, 2, 3, 1 };
	Solution solution;
	bool res = solution.validateStackSequences(pushed, poped);
	cout << res << endl;
	return 0;
}