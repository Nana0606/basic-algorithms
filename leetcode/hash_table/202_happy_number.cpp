# include <iostream>
# include <vector>
using namespace std;

/*
������Ҫ���������ѭ����ô�죿����ж��Ƿ�����ѭ��������ѭ����һ���Ǻ͵�һ��ֵ��ͬ�������Ǻ��м�õ���ĳ��ֵ��ͬ�������������һ��circle��¼֮ǰ���ֵ�����ֵ������ظ�����˵����������ѭ�����򷵻�false
*/

bool isHappy(int n) {
	if (n <= 0) return false;    //�����С��0��ֱ�ӷ���false
	if (n == 1) return true;

	int sum = 0;
	int operate = n;
	vector<int> circle;   //��¼�Ѿ����ֹ���Ԫ��
	circle.push_back(n);
	while (true){   //������ѭ������
		sum = 0;   //sum��0
		while (operate > 0){
			int temp = operate % 10;
			sum += temp * temp;
			operate = operate / 10;
		}   // end while�� ��ÿλ��ƽ����
		if (sum == 1) return true;
		operate = sum;    //ע��nӦ�ñ��sum
		
		//�ж��Ƿ��Ѿ����֣�����Ѿ����֣�ֱ�ӷ���0�����򣬽�sum���뵽circle��
		int i = 0;
		for (i = 0; i < circle.size(); i++){
			if (sum == circle[i]) return false;
		}
		if (i == circle.size()) circle.push_back(sum);
	}
	return false;
}

int main(){
	int n = 19;
	bool result = isHappy(n);
	cout << result << endl;
	return 0;
}