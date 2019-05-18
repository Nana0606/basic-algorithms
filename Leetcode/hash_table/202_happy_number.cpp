# include <iostream>
# include <vector>
using namespace std;

/*
这题主要点在于如果循环怎么办？如何判断是否满足循环条件，循环不一定是和第一个值相同，可能是和中间得到的某个值相同，所以这里采用一个circle记录之前出现的所有值，如果重复，则说明进入了死循环，则返回false
*/

bool isHappy(int n) {
	if (n <= 0) return false;    //若结果小于0，直接返回false
	if (n == 1) return true;

	int sum = 0;
	int operate = n;
	vector<int> circle;   //记录已经出现过的元素
	circle.push_back(n);
	while (true){   //若满足循环条件
		sum = 0;   //sum置0
		while (operate > 0){
			int temp = operate % 10;
			sum += temp * temp;
			operate = operate / 10;
		}   // end while， 求每位的平方和
		if (sum == 1) return true;
		operate = sum;    //注意n应该变成sum
		
		//判断是否已经出现，如果已经出现，直接返回0，否则，将sum加入到circle中
		int i = 0;
		for (i = 0; i < circle.size(); i++){
			if (sum == circle[i]) return false;
		}
		if (i == circle.size()) circle.push_back(sum);
	}
	return false;
}

int main(){
	int n = 19;
	bool result = isHappy(n);
	cout << result << endl;
	return 0;
}