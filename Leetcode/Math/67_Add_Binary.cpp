# include<iostream>
# include<string>
# include<sstream>
using namespace std;

string addBinary(string a, string b) {
	//p表示结果数据，结果数据的初始化
	int max_value = a.size() > b.size() ? a.size() : b.size();
	int *p = new int[max_value + 1];
	int index_p = max_value;
	for (int t = 0; t < max_value +1; t++){
		p[t] = 0;
	} 

	int i = a.size() - 1;
	int j = b.size() - 1;
	while (i >= 0 || j >= 0){    //注意这里只要有一个不为0，就需要继续算下去
		int a_value=0, b_value = 0;   //主要是为了一些短的字符串，将其添加数据置为0
		if (i >= 0){ 
			a_value = a[i] - '0';   // (a[i]- '0')表示将char类型转化成int型
		}
		if (j >=0){
			b_value = b[j] - '0';
		}
		int result = a_value + b_value + p[index_p];
		if (result >= 2){     //有可能出现a[i]=1,b[j]=1且进位也为1的情况
			p[index_p] = result % 2;
			p[index_p - 1] = 1;
		}
		else{
			p[index_p] = result;
		}
		i--;
		j--;
		index_p--;
	}
	//将int数组的数字转入string
	string result = "";
	int limit = (p[0] == 0 ? 1 : 0);
	for (int k = limit; k < max_value + 1; k++){
		stringstream ss;
		ss << p[k];
		result += ss.str();
	}
	return result;
}

int main(){
	string result = addBinary("1111", "1111");
	cout << result << endl;
	return 0;
}