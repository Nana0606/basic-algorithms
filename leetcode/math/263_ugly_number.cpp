# include <iostream>
using namespace std;

bool isUgly(int num) {
	if (num <= 0) return false;
	if (num == 1) return true;
	while (num != 1){
		if (num % 2 == 0){
			num /= 2;
		}
		else if (num % 3 == 0){
			num /= 3;
		}
		else if (num % 5 == 0){
			num /= 5;
		}
		else{
			return false;
		}
	}
	return true;
}


int main(){
	int n = 14;
	bool result = isUgly(n);
	cout << result << endl;
	return 0;
}