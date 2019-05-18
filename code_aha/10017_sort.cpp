#include <iostream>
#include <string>
using namespace std;

struct student{
	string name;
	int final_score;
	int class_evalute;
	char isCadres;    //�Ƿ�ѧ���ɲ�
	char isWestern;
	int paper_num;
};


int main(){
	int N; //N��ʾ�����ѧ������
	cin >> N;
	student *p = new student[N];
	int* money = new int[N];
	for (int i = 0; i < N; i++){
		money[i] = 0;
	}
	int p_index = 0; // ��¼�����������˶�Ӧ��p���±�
	int maxMoney = 0;   //���ڼ�¼��ǰ���Ľ����
	for (int i = 0; i < N; i++){
		cin >> p[i].name >> p[i].final_score >> p[i].class_evalute >> p[i].isCadres >> p[i].isWestern >> p[i].paper_num;
		if (p[i].final_score > 80 && p[i].paper_num >= 1)
			money[i] += 8000;
		if (p[i].final_score > 85 && p[i].class_evalute > 80)
			money[i] += 4000;
		if (p[i].final_score > 90)
			money[i] += 2000;
		if (p[i].final_score > 85 && p[i].isWestern == 'Y')
			money[i] += 1000;
		if (p[i].class_evalute > 80 && p[i].isCadres == 'Y')
			money[i] += 850;
		if (maxMoney < money[i]){
			p_index = i;
			maxMoney = money[i];
		}
	}
	int total = 0;
	cout << p[p_index].name << endl;
	cout << maxMoney << endl;
	for (int i = 0; i < N; i++){
		total += money[i];
	}
	cout << total << endl;
	return 0;
}