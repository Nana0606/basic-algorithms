# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

vector<pair<int, int> > reconstructQueue(vector<pair<int, int>>& people) {
	//排序
	auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){
		return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
	};
	sort(people.begin(), people.end(), comp);

	//插入。p.second代表前面有几个比他大于等于的数据，即数组顺序
	vector<pair<int, int> > result;
	for (auto& p : people){
		result.insert(result.begin() + p.second, p);
	}
	return result;
}

int main(){
	vector<pair<int, int>> people = { { 7, 0 }, { 4, 4 }, { 7, 1 }, { 5, 0 }, { 6, 1 }, { 5, 2 } };
	vector<pair<int, int> > result = reconstructQueue(people);
	vector<pair<int, int> >::iterator it;
	for (it = result.begin(); it < result.end(); it++){
		cout << " " << (*it).first << " " << (*it).second;
	}
	cout << endl;
	return 0;
}