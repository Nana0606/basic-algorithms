# include <iostream>
using namespace std;

struct queue{
	int data[200000];
	int head;
	int tail;
};

int main(){
	int N;    //NλQQ����
	cin >> N;
	queue q;
	//��ʼ������
	q.head = 0;
	q.tail = 0;
	for (int i = 0; i < N; i++){
		cin >> q.data[q.tail];
		q.tail++;
	}
	while (q.head < q.tail){
		cout << q.data[q.head++] << " ";
		q.data[q.tail++] = q.data[q.head++];
	}
	cout << endl;
	return 0;
}