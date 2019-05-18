# include <iostream>
# include <vector>
using namespace std;

//AC,就是统计两个相邻1之间的最大距离。
int binaryGap(int N) {
	vector<int> temp;  //store the index of '1'
	int index = 0;
	while (N > 0){
		int remainder = N % 2;
		if (remainder == 1){
			temp.push_back(index);
		}
		N /= 2;
		index += 1;
	}
	int max = 1;
	if (int(temp.size()) == 1) return 0;
	for (int i = 1; i < int(temp.size()); i++){
		int gap = temp[i] - temp[i - 1];  // get the gap between the consecutive 1's.
		if (max < gap) max = gap;

	}
	return max;
}

int main(){
	int N = 8;
	int res = binaryGap(N);
	cout << res << endl;
	return 0;
}