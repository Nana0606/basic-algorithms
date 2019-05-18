#include <iostream>
#include <algorithm>
#include <vector>
#include<cstdlib>
using namespace std;

/*
题目描述：
	题目描述(ID:12150)
	标题:	2.1-2顺序的分数
	标签:	搜索 排序
	详情:	输入一个自然数N,对于一个最简分数a/b（分子和分母互质的分数）,满足1<=b<=N,0<=a/b<=1,请找出所有满足条件的分数。
	这有一个例子，当N=5时，所有解为：
	0/1 1/5 1/4 1/3 2/5 1/2 3/5 2/3 3/4 4/5 1/1
	给定一个自然数N，1<=n<=160，请编程按分数值递增的顺序输出所有解。
	注：①0和任意自然数的最大公约数就是那个自然数②互质指最大公约数等于1的两个自然数。
	输入格式:	
	单独的一行　一个自然数N(1..160)
	输出格式:	
	每个分数单独占一行，按照大小次序排列
	样例:	
	输入

	5
	输出

	0/1
	1/5
	1/4
	1/3
	2/5
	1/2
	3/5
	2/3
	3/4
	4/5
	1/1
*/

struct data{
	int a;   //分子
	int b;   //分母
};

vector<data> p;

int maxgcd(int a, int b){
	int temp = min(a, b);
	if (a == 0){    //对于第一条数据，如果b==0，则返回a
		return b;
	}
	else{
		for (temp = min(a, b); temp >= 1; temp--){
			if ((a%temp == 0) && (b%temp == 0))
				return temp;
		}
	}
}

bool mycmp(const data &p1, const data &p2){
	return p1.a*p2.b < p2.a*p1.b ? true : false;
}

//int maxgcd(int a, int b)
//{
//	return b == 0 ? a : maxgcd(b, a%b);
//}

int main(){
	int N; //N表示给定的自然数
	cin >> N;
	data temp;
	for (int b = 1; b <= N; b++){
		for (int a = 0; a <= b; a++){
			if (maxgcd(a, b) == 1){
				temp.a = a;
				temp.b = b;
				p.push_back(temp);
				//cout << "将以下元素加入： " << a << " " << b << endl;
			}
		}
	}

	sort(p.begin(), p.end(), mycmp);
	
	for (int k = 0; k < p.size(); k++){
		cout << p[k].a << "/" << p[k].b << endl;
	}
}