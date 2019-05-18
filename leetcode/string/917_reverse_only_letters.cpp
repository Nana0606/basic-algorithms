# include <iostream>
# include <string>
using namespace std;

//AC，思想：对于不是字母的元素，放着不动，对于是字母的元素，前面的和后面的进行交换
string reverseOnlyLetters(string S) {
	int left = 0;
	int right = S.length() - 1;
	while (left < right){
		//若有多个不满足的元素，需要多次后移，所以使用while，但是注意使用while的时候，需要防止left和right下标超出范围。
		while (!((S[left] >= 'a' && S[left] <= 'z') || (S[left] >= 'A' && S[left] <= 'Z')) && left < right){
			left++;
		}
		while (!((S[right] >= 'a' && S[right] <= 'z') || (S[right] >= 'A' && S[right] <= 'Z')) && left < right){
			right--;
		}
		if (left < right){
			//S[left]和S[right]都是字母
			char temp = S[left];
			S[left] = S[right];
			S[right] = temp;
			left++;
			right--;
		}
	}
	return S;
}

int main(){
	string S = "7_28]";
	string res = reverseOnlyLetters(S);
	cout << res << endl;
	return 0;
}