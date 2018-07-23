# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/*
����:	1.2-1��ţ��
��ǩ:	ģ�� ����
����:
����ũ��ÿ���峿5���𴲣�Ȼ��ȥţ���3ͷţ���̡���һ��ũ����300��(��5�㿪ʼ��ʱ)������ţ���̣�һֱ��1000�롣�ڶ���ũ����700�뿪ʼ���� 1200�������������ũ����1500�뿪ʼ2100��������ڼ����������һ��ũ���ڼ��̵�����ʱ��Ϊ900��(��300�뵽1200��)����������˼��̵�����ʱ��(�Ӽ��̿�ʼһֱ�����̽���)Ϊ300��(��1200�뵽1500��)��
��������Ǳ�һ�����򣬶���һ����N��ũ��(1 <= N <= 5000)��Nͷţ�Ĺ���ʱ���б�������������(������Ϊ��λ):
�������һ���ڼ��̵�ʱ��Ρ�
������˼��̵�ʱ��Ρ��������˼��̿�ʼ����
�����ʽ:
��1�У�һ������N��
������N�У�ÿ������С��1000000�ķǸ���������ʾһ��ũ��Ŀ�ʼʱ�������ʱ�̡�
�����ʽ:
һ�У���������������Ŀ��Ҫ��������𰸡�
��ʾ:	USACO Training
����:	ÿ�����Ե�1��
����:
����

3
300 1000
700 1200
1500 2100
���

900 300
*/
//ע���ʼ���Ƕο���ʱ�䣨����û���˿�ʼ����ʱ�����ǲ���Ҫ�������ڵġ�

int main(){
	int N; // N��ʾ��ũ������
	cin >> N;
	int max_len = 1000000;
	int start_time = 0;
	int end_time = 0;
	int *p = new int[max_len];
	for (int i = 0; i < max_len; ++i){    //��0��ʼ��0��ʾ�����һ�������һ��p[1000000]��ʾһ������ķ���0����Ϣ
		p[i] = 0;
	}
	// ��������ũ���̵�ʱ�����Ϊ1.
	for (int i = 0; i < N; i++){
		cin >> start_time >> end_time;
		for (int j = start_time + 1; j <= end_time; ++j){
			p[j] = 1;
		}
	}

	//�������еı任�ڵ㣬��Ӽ���״̬��Ϊδ����״̬�����ߴ�δ����״̬��Ϊ����״̬��
	vector<int>  time;
	for (int i = 0; i < max_len - 1; i++){
		if ((p[i] == 0 && p[i + 1] == 1) || (p[i] == 1 && p[i + 1] == 0)){
			time.push_back(i);
		}
	}
	int max_free_internal = 0;   //�����ʱ��
	int max_busy_internal = 0;   //�����ʱ��
	int internal = 0;    //��¼���̻���еĳ���ʱ��

	for (int i = 0; i < (int)time.size()-1; i++){
		internal = time[i + 1] - time[i];
		//����time vector���ԣ���һ�������������ֶ���æµ״̬��
		if (i % 2 == 0){   //æµ״̬
			max_busy_internal = max_busy_internal < internal ? internal:max_busy_internal;
		}
		else{     //����״̬
			max_free_internal = max_free_internal < internal ? internal:max_free_internal;
		}
	}
	cout << max_busy_internal << " " << max_free_internal << endl;
	return 0;
}