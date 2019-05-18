#include <iostream>
#include <algorithm>
#include <vector>
#include<cstdlib>
using namespace std;

/*
��Ŀ������
	��Ŀ����(ID:12150)
	����:	2.1-2˳��ķ���
	��ǩ:	���� ����
	����:	����һ����Ȼ��N,����һ��������a/b�����Ӻͷ�ĸ���ʵķ�����,����1<=b<=N,0<=a/b<=1,���ҳ��������������ķ�����
	����һ�����ӣ���N=5ʱ�����н�Ϊ��
	0/1 1/5 1/4 1/3 2/5 1/2 3/5 2/3 3/4 4/5 1/1
	����һ����Ȼ��N��1<=n<=160�����̰�����ֵ������˳��������н⡣
	ע����0��������Ȼ�������Լ�������Ǹ���Ȼ���ڻ���ָ���Լ������1��������Ȼ����
	�����ʽ:	
	������һ�С�һ����Ȼ��N(1..160)
	�����ʽ:	
	ÿ����������ռһ�У����մ�С��������
	����:	
	����

	5
	���

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
	int a;   //����
	int b;   //��ĸ
};

vector<data> p;

int maxgcd(int a, int b){
	int temp = min(a, b);
	if (a == 0){    //���ڵ�һ�����ݣ����b==0���򷵻�a
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
	int N; //N��ʾ��������Ȼ��
	cin >> N;
	data temp;
	for (int b = 1; b <= N; b++){
		for (int a = 0; a <= b; a++){
			if (maxgcd(a, b) == 1){
				temp.a = a;
				temp.b = b;
				p.push_back(temp);
				//cout << "������Ԫ�ؼ��룺 " << a << " " << b << endl;
			}
		}
	}

	sort(p.begin(), p.end(), mycmp);
	
	for (int k = 0; k < p.size(); k++){
		cout << p[k].a << "/" << p[k].b << endl;
	}
}