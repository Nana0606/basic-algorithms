# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
# include <map>
using namespace std;

//˼·�����Ƚ����е㰴�д洢��map�У�key�Ǻ����꣬value�����к�������key�ĵ�������깹�ɵ�set
class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		int min_val = INT_MAX;
		map<int, set<int> > map;
		// ��pointsӳ�䵽һ��map��
		for (int i = 0; i < int(points.size()); i++){
			if (map.find(points[i][0]) != map.end()){  //����
				map[points[i][0]].insert(points[i][1]);
			}
			else{
				set<int> temp_set;
				temp_set.insert(points[i][1]);
				map.insert(pair<int, set<int> >(points[i][0], temp_set));
			}
		}
		// �����ڵ㣬O(N^2)
		for (int i = 0; i <int(points.size()); i++){
			for (int j = i+1; j <int(points.size()); j++){
				// ��ʾ����������ͬ��x������ͬ��y������ֻ��б�ߣ�����������չ��������
				if (points[i][0] == points[j][0] || points[i][1] == points[j][1]){
					continue;
				}
				if (map[points[i][0]].find(points[j][1]) != map[points[i][0]].end() && map[points[j][0]].find(points[i][1]) != map[points[j][0]].end()){
					//˵������
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