#include <iostream>
#include <string>
using namespace std;

struct student{
	string name;
	int final_score;
	int class_evalute;
	char isCadres;    //是否学生干部
	char isWestern;
	int paper_num;
	int money;
};

int main(){
	int N; //N表示输入的学生个数
	cin >> N;
	student *p = new student[N];
	int total = 0;
	for (int i = 0; i < N; i++){
		int onebody_money = 0;
		cin >> p[i].name >> p[i].final_score >> p[i].class_evalute >> p[i].isCadres >> p[i].isWestern >> p[i].paper_num;
		if (p[i].final_score > 80 && p[i].paper_num >= 1)
			onebody_money += 8000;
		if (p[i].final_score > 85 && p[i].class_evalute > 80)
			onebody_money += 4000;
		if (p[i].final_score > 90)
			onebody_money += 2000;
		if (p[i].final_score > 85 && p[i].isWestern == 'Y')
			onebody_money += 1000;
		if (p[i].class_evalute > 80 && p[i].isCadres == 'Y')
			onebody_money += 850;
		p[i].money = onebody_money;
		total += onebody_money;
	}

	// 对数组p进行冒泡排序
	for (int i = 0; i < N - 1; i++) {   //外层循环n-1次
		for (int j = 0; j <= N - i - 2; j++){
			if (p[j].money < p[j + 1].money){
				student temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	} // end for 

	//for (int i = 0; i < N; i++){
	//	cout << p[i].money << " ";
	//}
	//cout << endl;

	cout << p[0].name << "\n" << p[0].money << "\n" << total << endl;
}