# include <iostream>
# include <algorithm>
using namespace std;

struct Farmer{
	int start;    //开始挤奶时间
	int end;      //挤奶结束时间
};

bool mycompare(const Farmer &f1, const Farmer &f2){
	return f1.start == f2.start ? f1.end < f2.end : f1.start < f2.start;
}

int main(){
	int N; //表示奶农的人数
	cin >> N;
	Farmer *p = new Farmer[N];
	for (int i = 0; i < N; i++){
		cin >> p[i].start >> p[i].end;
	}
	sort(p, p + N, mycompare);
	int min_busy_time = p[0].start;   //表示持续挤奶时间的开始时间
	int max_busy_time = p[0].end;   //表示持续挤奶时间的最大结束时间
	int internal_busy = max_busy_time - min_busy_time;   //挤奶最长持续时间
	int internal_free = 0;  //最长无人挤奶时间
	for (int i = 1; i < N; i++){
		if (p[i].start <= max_busy_time){    //下一个的开始时间在前一个结束时间之前
			max_busy_time = max(p[i].end, max_busy_time);   //更新持续挤奶时间的最大结束时间，之所以取p[i].end和max_busy_time的最大值，是考虑p[i].end比max_busy_time还小的情况，所以不能直接更新为p[i].end(可能后一个人挤奶开始时间比前一个人晚、结束时间比前一个人早)。
			if (internal_busy < (max_busy_time - min_busy_time)){
				internal_busy = max_busy_time - min_busy_time;   //更新最长挤奶时间
			}
		}
		else if (p[i].start > max_busy_time){
			if (internal_free < (p[i].start - max_busy_time)){
				internal_free = p[i].start - max_busy_time;    //更新最长无人挤奶时间
			}
			min_busy_time = p[i].start;    //重新开始下一阶段的持续挤奶时间记录
			max_busy_time = p[i].end;
		}
	}
	cout << internal_busy << " " << internal_free << endl;
	return 0;
}