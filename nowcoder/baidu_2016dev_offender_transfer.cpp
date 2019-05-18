# include <iostream>
using namespace std;

// AC: 90%

int main(){
	int n, t, c;
	while (cin >> n){
		cin >> t >> c;
		int *p = new int[n];
		for (int i = 0; i < n; i++){
			cin >> p[i];
		}
		if (c > n) return 0;
		int count = 0;
		int sum = 0;
		for (int s = 0; s < n; s++){
			if (s < c-1) sum += p[s];
			else{
				sum += p[s];
				if (sum < t) count++;
				sum -= p[s - c + 1];
			}
		}
		cout << count << endl;
	}
	return 0;
}