# include <iostream>
# include <vector>
using namespace std;

/**
// Method1£º common solution.
// converting decimal into binary.
int getOneNum(int n){
	int total = 0;
	int temp = n;
	while (temp){
		if (temp % 2 == 1) total++;
		temp /= 2;
	}
	return total;
}

vector<int> countBits(int num) {
	vector<int> result;
	for (int i = 0; i <= num; i++){
		int num = getOneNum(i);
		result.push_back(num);
	} 
	return result;
}
*/

// Method2£ºdp
vector<int> countBits(int num) {
	vector<int> result(num + 1, 0);
	for(int i = 1; i <= num; i++){
		result[i] = result[i / 2] + i % 2;
	}
	return result;
}

int main(){
	int num = 2;
	vector<int> result = countBits(num); 
	vector<int>::iterator it;
	for (it = result.begin(); it < result.end(); it++){
		cout << *it << endl;
	}
	return 0;
}