# include <iostream>
# include <algorithm>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int minx = (int)1e9, miny = (int)1e9, maxx = (int)-1e9, maxy = (int)-1e9;
		int x, y;
		while (n-- >0){
			cin >> x >> y;
			minx = min(x, minx);
			maxx = max(x, maxx);
			miny = min(y, miny);
			maxy = max(y, maxy);
		}
		int edge = max(abs(maxx - minx), abs(maxy - miny));
		cout << edge * edge << endl;
	}
	return 0;
}