# include <iostream>
# include <vector>
using namespace std;

#define INT_MAX 2147483647

//题目：度度熊回家
//网址：https://www.nowcoder.com/question/next?pid=4998655&qid=95824&tid=20642690

int main(){
	int N;
	cin >> N;
	int len_N = N;
	int point;
	vector<int> vec;
	while (N-- > 0){
		cin >> point;
		vec.push_back(point);
	}
	int min = INT_MAX;
	for (int i = 1; i <= len_N - 2; i++){
		int res = 0;
		int j = 0, k = 1;
		while (k <= len_N - 1){
			if (k != i){
				res += abs(vec[k] - vec[j]);
				k++;
				j++;
			}
			else{
				k++;
				res += abs(vec[k] - vec[j]);
				k++;
				j+=2;
			}
		}
		if (res < min){ 
			min = res; 
		}
	}
	cout << min << endl;
	return 0;
}