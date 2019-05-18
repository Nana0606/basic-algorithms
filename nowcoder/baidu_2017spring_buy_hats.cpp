# include <iostream>
using namespace std;

//ÌâÄ¿£ºÂòÃ±×Ó
//ÍøÖ·£ºhttps://www.nowcoder.com/test/question/f3aaf8fedcea43c6b12a11710068726b?pid=4998655&tid=20642690

int main(){
	int N;
	cin >> N;
	int price;
	int lis[1001];
	for (int i = 0; i < 1001; i++){
		lis[i] = 0;
	}
	while (N-- > 0){
		cin >> price;
		lis[price] = 1;
	}
	int j = 0;
	for (int i = 0; i < 1001; i++){
		if (lis[i] == 1) j++;
		if (j == 3) { 
			cout << i << endl;
			break;
		}
	}
	if (j < 3) cout << -1 << endl;
	return 0;
}