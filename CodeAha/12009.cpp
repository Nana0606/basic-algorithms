# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/*
标题:	1.2-1挤牛奶
标签:	模拟 排序
详情:
三个农民每天清晨5点起床，然后去牛棚给3头牛挤奶。第一个农民在300秒(从5点开始计时)给他的牛挤奶，一直到1000秒。第二个农民在700秒开始，在 1200秒结束。第三个农民在1500秒开始2100秒结束。期间最长的至少有一个农民在挤奶的连续时间为900秒(从300秒到1200秒)，而最长的无人挤奶的连续时间(从挤奶开始一直到挤奶结束)为300秒(从1200秒到1500秒)。
你的任务是编一个程序，读入一个有N个农民(1 <= N <= 5000)挤N头牛的工作时间列表，计算以下两点(均以秒为单位):
最长至少有一人在挤奶的时间段。
最长的无人挤奶的时间段。（从有人挤奶开始算起）
输入格式:
第1行：一个整数N。
接下来N行：每行两个小于1000000的非负整数，表示一个农民的开始时刻与结束时刻。
输出格式:
一行，两个整数，即题目所要求的两个答案。
提示:	USACO Training
限制:	每个测试点1秒
样例:
输入

3
300 1000
700 1200
1500 2100
输出

900 300
*/
//注：最开始的那段空闲时间（即还没有人开始挤奶时），是不需要计算在内的。

int main(){
	int N; // N表示奶农的人数
	cin >> N;
	int max_len = 1000000;
	int start_time = 0;
	int end_time = 0;
	int *p = new int[max_len];
	for (int i = 0; i < max_len; ++i){    //从0开始，0表示最初的一个，最后一个p[1000000]表示一个冗余的放置0的信息
		p[i] = 0;
	}
	// 将所有奶农挤奶的时间点置为1.
	for (int i = 0; i < N; i++){
		cin >> start_time >> end_time;
		for (int j = start_time + 1; j <= end_time; ++j){
			p[j] = 1;
		}
	}

	//计算所有的变换节点，如从挤奶状态变为未挤奶状态，或者从未挤奶状态变为挤奶状态。
	vector<int>  time;
	for (int i = 0; i < max_len - 1; i++){
		if ((p[i] == 0 && p[i + 1] == 1) || (p[i] == 1 && p[i + 1] == 0)){
			time.push_back(i);
		}
	}
	int max_free_internal = 0;   //最长空闲时间
	int max_busy_internal = 0;   //最长挤奶时间
	int internal = 0;    //记录挤奶或空闲的持续时间

	for (int i = 0; i < (int)time.size()-1; i++){
		internal = time[i + 1] - time[i];
		//对于time vector而言，第一个减出来的数字都是忙碌状态的
		if (i % 2 == 0){   //忙碌状态
			max_busy_internal = max_busy_internal < internal ? internal:max_busy_internal;
		}
		else{     //空闲状态
			max_free_internal = max_free_internal < internal ? internal:max_free_internal;
		}
	}
	cout << max_busy_internal << " " << max_free_internal << endl;
	return 0;
}