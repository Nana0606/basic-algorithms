# include <iostream>
# include <algorithm>
using namespace std;

struct student{
	int id;  //学号
	int yw;    //语文成绩
	int sx;    //数学成绩
	int yy;    //英语成绩
	int total;
};

bool mycompare(const student &a, const student &b){
	if (a.total > b.total){
		return true;
	}
	else if (a.total < b.total){
		return false;
	}
	else{
		if (a.yw > b.yw){
			return true;
		}
		else if (a.yw < b.yw){
			return false;
		}
		else{
			return a.id < b.id ? true : false;
		}
	}
}

int main(){
	int n;
	cin >> n;
	student *p = new student[n];
	for (int i = 0; i < n; i++){
		p[i].id = i + 1;
		cin >> p[i].yw >> p[i].sx >> p[i].yy;
		p[i].total = p[i].yw + p[i].sx + p[i].yy;
	}
	sort(p, p+n, mycompare);    //自定义compare函数
	for (int i = 0; i < 5; i++){   //输出前5个信息
		cout << p[i].id << " " << p[i].total << endl;
	}
	return 0;
}