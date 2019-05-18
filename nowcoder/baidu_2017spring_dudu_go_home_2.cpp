# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//题目：度度熊回家
//网址：https://www.nowcoder.com/question/next?pid=4998655&qid=95824&tid=206443599

int main(){
	int N;
	cin >> N;
	int value;
	vector<int> vec;
	int len_N = N;
	while (N-- > 0){
		cin >> value;
		vec.push_back(value);
	}
	int sum = 0;  //表示全部距离
	for (int i = 0; i < len_N-1; i++){
		sum += abs(vec[i + 1] - vec[i]);
	}
	int max_diff = 0;
	for (int i = 1; i < len_N - 1; i++){
		max_diff = max(max_diff, abs(vec[i + 1] - vec[i]) + abs(vec[i] - vec[i - 1]) - abs(vec[i + 1] - vec[i - 1]));
	}
	cout << sum - max_diff << endl;
	return 0;
}