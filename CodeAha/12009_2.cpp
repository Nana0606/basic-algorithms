# include <iostream>
# include <algorithm>
using namespace std;

struct Farmer{
	int start;    //��ʼ����ʱ��
	int end;      //���̽���ʱ��
};

bool mycompare(const Farmer &f1, const Farmer &f2){
	return f1.start == f2.start ? f1.end < f2.end : f1.start < f2.start;
}

int main(){
	int N; //��ʾ��ũ������
	cin >> N;
	Farmer *p = new Farmer[N];
	for (int i = 0; i < N; i++){
		cin >> p[i].start >> p[i].end;
	}
	sort(p, p + N, mycompare);
	int min_busy_time = p[0].start;   //��ʾ��������ʱ��Ŀ�ʼʱ��
	int max_busy_time = p[0].end;   //��ʾ��������ʱ���������ʱ��
	int internal_busy = max_busy_time - min_busy_time;   //���������ʱ��
	int internal_free = 0;  //����˼���ʱ��
	for (int i = 1; i < N; i++){
		if (p[i].start <= max_busy_time){    //��һ���Ŀ�ʼʱ����ǰһ������ʱ��֮ǰ
			max_busy_time = max(p[i].end, max_busy_time);   //���³�������ʱ���������ʱ�䣬֮����ȡp[i].end��max_busy_time�����ֵ���ǿ���p[i].end��max_busy_time��С����������Բ���ֱ�Ӹ���Ϊp[i].end(���ܺ�һ���˼��̿�ʼʱ���ǰһ����������ʱ���ǰһ������)��
			if (internal_busy < (max_busy_time - min_busy_time)){
				internal_busy = max_busy_time - min_busy_time;   //���������ʱ��
			}
		}
		else if (p[i].start > max_busy_time){
			if (internal_free < (p[i].start - max_busy_time)){
				internal_free = p[i].start - max_busy_time;    //��������˼���ʱ��
			}
			min_busy_time = p[i].start;    //���¿�ʼ��һ�׶εĳ�������ʱ���¼
			max_busy_time = p[i].end;
		}
	}
	cout << internal_busy << " " << internal_free << endl;
	return 0;
}