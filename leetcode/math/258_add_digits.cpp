# include <iostream>
using namespace std;

//�������
/*
int addDigits(int num) {
	int total_sum = num;   //��ʾ������sum�������Ƿ�С��10�ģ�С��10����ֹͣ
	while (total_sum > 9){
		int sum = 0;  //sum�����������һ������ֹͣ��total_sum���������λ���֮��
		while (total_sum > 0){
			sum += total_sum % 10;
			total_sum /= 10;
		}
		total_sum = sum;
	}	
	return total_sum;
}
*/

//����������������
//��ʽ��dr(n)=1+((n-1) mod 9)
int addDigits(int num) {
	return 1 + (num - 1) % 9;
}

int main(){
	int num = 139;
	int res = addDigits(num);
	cout << res << endl;
	return 0;
}