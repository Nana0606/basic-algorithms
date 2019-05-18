# include <iostream>
# include <algorithm>
using namespace std;

struct student{
	int id;  //ѧ��
	int yw;    //���ĳɼ�
	int sx;    //��ѧ�ɼ�
	int yy;    //Ӣ��ɼ�
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
	sort(p, p+n, mycompare);    //�Զ���compare����
	for (int i = 0; i < 5; i++){   //���ǰ5����Ϣ
		cout << p[i].id << " " << p[i].total << endl;
	}
	return 0;
}