# include <iostream>
# include <vector>
using namespace std;

// AC, easy
struct saveMoney{
	int fiveNum;
	int tenNum;
	int tweetyNum;
};

bool lemonadeChange(vector<int>& bills) {
	saveMoney save_money = { 0, 0, 0 };
	for (int i = 0; i < bills.size(); i++){
		if (bills[i] == 5) save_money.fiveNum++;
		else if (bills[i] == 10){
			if (save_money.fiveNum >= 1){
				save_money.fiveNum--;
				save_money.tenNum++;
			}
			else return false;
		}
		else{
			if (save_money.tenNum >= 1 && save_money.fiveNum >= 1){
				save_money.tenNum--;
				save_money.fiveNum--;
				save_money.tweetyNum++;
			}
			else if (save_money.fiveNum >= 3){
				save_money.fiveNum -= 3;
				save_money.tweetyNum++;
			}
			else{
				return false;
			}
		}
	}
	return true;
}

int main(){
	vector<int> bills = { 10, 10 };
	bool res = lemonadeChange(bills);
	cout << res << endl;
	return 0;
}