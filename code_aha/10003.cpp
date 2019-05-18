# include<iostream>
using namespace std;

int main(){
	int *p = new int[7];
	int time1;
	int time2;
	int max_value = 0;
	int max_index = -1;
	for (int i = 0; i < 7; i++){
		cin >> time1;
		cin >> time2;
		p[i] = time1 + time2;
		if (max_value < p[i]){
			max_value = p[i];
			max_index = i;
		}
	}
	if (max_value <= 8){
		cout << "0" << endl;
	}
	else{
		cout << max_index + 1 << endl;
	}
	return 0;
}