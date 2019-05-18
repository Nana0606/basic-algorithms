# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

bool isUgly(int num, vector<int>& primes) {
	if (num <= 0) return false;
	if (num == 1) return true;
	while (num != 1){
		int i = 0;
		int flag = 0;    //������flag�����ƣ���Ϊ����һ��ѭ���У�ֻҪ��һ���ǿ��Ա������ģ�����ֱ���ж�Ϊfalse
		for (i = 0; i < primes.size(); i++){
			if (num == 1) return true;   
			while(num % primes[i] == 0){
				num /= primes[i];
				flag = 1;
			}
		}
		if (flag == 0) return false;
	}
	return true;
}

/**
//���һ��case��ʱ
int nthSuperUglyNumber(int n, vector<int>& primes) {
	int max_value = 1;
	if (n == 1)
		return max_value;
	int circle = 2;
	for (int i = 2; i <= n; i++){
		while (!isUgly(circle, primes)){
			circle++;
		}
		max_value = circle;
		circle++;
		//cout << max_value << endl;
	}
	return max_value;
}
*/

// AC
int nthSuperUglyNumber(int n, vector<int>& primes){
	if (n <= 0) return false;
	if (n == 1) return true;
	int *index = new int[primes.size()];
	for (int i = 0; i < primes.size(); i++){
		index[i] = 0;     //��ʾprimes[i]�Ѿ����ֵĴ���
	}
	vector<int> res(n);    //ע��洢��n�����ݣ���˴�СΪn
	res[0] = 1;
	for (int i = 1; i < n; i++){
		int min_value = res[index[0]] * primes[0];
		if (primes.size() > 1){   //��primes.size() < 1������Сֵ����min_value�������ٱȽϡ�
			for (int j = 1; j < primes.size(); j++){
				res[i] = min(min_value, res[index[j]] * primes[j]);    //res�洢������������Сֵ��ʹ�ô洢������ģ� �����Ƚ�������ȡ��n��ֵ��
				if (min_value > res[index[j]] * primes[j]){
					min_value = res[index[j]] * primes[j];
				}
			}
		}
		else{
			res[i] = min_value;
		}
		
		for (int j = 0; j < primes.size(); j++){
			if (res[i] == res[index[j]] * primes[j])  index[j] ++;    // ����index[j]����primes[j]�����˶��ٴ�
		}
	}
	return res[n - 1];
}

int main(){
	int n = 2;
	vector<int> primes = { 2 };
	int result = nthSuperUglyNumber(n, primes);
	cout << result << endl;
	return 0;
}