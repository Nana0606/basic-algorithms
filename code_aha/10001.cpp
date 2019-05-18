# include <iostream>
using namespace std;

int main(){
	int *p = new int[10];
	int height;
	for (int i = 0; i < 10; i++){
		cin >> p[i];
	}
	cin >> height;
	int count = 0;
	for (int i = 0; i < 10; i++){
		if (p[i] <= (height + 30)){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}