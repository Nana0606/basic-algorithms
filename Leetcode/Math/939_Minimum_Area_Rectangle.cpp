# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
# include <map>
using namespace std;

//思路：首先将所有点按行存储在map中，key是横坐标，value是所有横坐标是key的点的纵坐标构成的set
class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		int min_val = INT_MAX;
		map<int, set<int> > map;
		// 将points映射到一个map中
		for (int i = 0; i < int(points.size()); i++){
			if (map.find(points[i][0]) != map.end()){  //存在
				map[points[i][0]].insert(points[i][1]);
			}
			else{
				set<int> temp_set;
				temp_set.insert(points[i][1]);
				map.insert(pair<int, set<int> >(points[i][0], temp_set));
			}
		}
		// 遍历节点，O(N^2)
		for (int i = 0; i <int(points.size()); i++){
			for (int j = i+1; j <int(points.size()); j++){
				// 表示两个点有相同的x或者相同的y，我们只找斜边，这样可以扩展到长方形
				if (points[i][0] == points[j][0] || points[i][1] == points[j][1]){
					continue;
				}
				if (map[points[i][0]].find(points[j][1]) != map[points[i][0]].end() && map[points[j][0]].find(points[i][1]) != map[points[j][0]].end()){
					//说明存在
					int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
					if (min_val > area){
						min_val = area;
					}
				}
			}
		}
		return min_val == INT_MAX?0: min_val;
	}
};

int main(){
	vector<vector<int> > points = { { 1, 1 }, { 1, 3 }, { 3, 1 }, { 3, 3 }, { 2, 2 } };
	Solution solution;
	int res = solution.minAreaRect(points);
	cout << res << endl;
	return 0;
}