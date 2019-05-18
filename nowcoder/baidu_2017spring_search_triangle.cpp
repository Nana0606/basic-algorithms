# include <iostream>
# include <vector>
# include <iomanip>
using namespace std;

# define MIN_VALUE -1;

//题目：寻找三角形
//地址：https://www.nowcoder.com/question/next?pid=4998655&qid=95825&tid=20642690

struct point{
	char type;
	int x;
	int y;
	int z;
};

double calcTriangle(point p1, point p2, point p3){
	double area = -1;
	double sides[3];
	sides[0] = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
	sides[1] = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2) + pow(p1.z - p3.z, 2));
	sides[2] = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2) + pow(p2.z - p3.z, 2));

	//不能构成三角形;
	if (sides[0] + sides[1] <= sides[2] || sides[0] + sides[2] <= sides[1] || sides[1] + sides[2] <= sides[0]) return area;

	//利用海伦公式。s=sqr(p*(p-a)(p-b)(p-c)); 
	double p = (sides[0] + sides[1] + sides[2]) / 2; //半周长;
	area = sqrt(p*(p - sides[0])*(p - sides[1])*(p - sides[2]));

	return area;
}

int main(){
	int N;
	cin >> N;
	int len_N = N;
	char type;
	int x, y, z;
	vector<point> vec;
	while (N-- > 0){
		cin >> type >> x >> y >> z;
		point p = { type, x, y, z };
		vec.push_back(p);
	}
	double max = MIN_VALUE;
	for (int i = 0; i < len_N-2; i++){
		for (int j = i + 1; j < len_N - 1; j++){
			for (int k = j + 1; k < len_N; k++){
				if ((vec[i].type == vec[j].type && vec[j].type == vec[k].type) || (vec[i].type != vec[j].type && vec[j].type != vec[k].type && vec[i].type != vec[k].type)){
					double area = calcTriangle(vec[i], vec[j], vec[k]);
					if (area > max) max = area;
				}
			}
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(5)<< max << endl;
	return 0;
}