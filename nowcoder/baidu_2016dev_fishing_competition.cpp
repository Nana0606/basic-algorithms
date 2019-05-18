# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;

int main(){
	int n, m, x, y, t;
	while (cin >> n){
		double ss = 0;
		double **p;
		p = new double*[n];
		cin >> m >> x >> y >> t;
		for (int i = 0; i < n; i++){
			p[i] = new double[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				cin >> p[i][j];
				ss += p[i][j];
			}
		double cc = 1 - pow((1-p[x - 1][y - 1]),t);
		ss = ss / m/n;
		ss = 1 - pow((1 - ss), t);

		if (cc == ss){
			cout << "equal" << endl;
			cout << setiosflags(ios::fixed) << setprecision(2) << ss << endl;
		}
		else if (cc > ss){
			cout << "cc" << endl;
			cout << setiosflags(ios::fixed) << setprecision(2) << cc << endl;
		}
		else{
			cout << "ss" << endl;
			cout << setiosflags(ios::fixed) << setprecision(2) << ss << endl;
		}
	}
	return 0;
}