# include<iostream>
# include<string>
# include<sstream>
using namespace std;

string addBinary(string a, string b) {
	//p��ʾ������ݣ�������ݵĳ�ʼ��
	int max_value = a.size() > b.size() ? a.size() : b.size();
	int *p = new int[max_value + 1];
	int index_p = max_value;
	for (int t = 0; t < max_value +1; t++){
		p[t] = 0;
	} 

	int i = a.size() - 1;
	int j = b.size() - 1;
	while (i >= 0 || j >= 0){    //ע������ֻҪ��һ����Ϊ0������Ҫ��������ȥ
		int a_value=0, b_value = 0;   //��Ҫ��Ϊ��һЩ�̵��ַ������������������Ϊ0
		if (i >= 0){ 
			a_value = a[i] - '0';   // (a[i]- '0')��ʾ��char����ת����int��
		}
		if (j >=0){
			b_value = b[j] - '0';
		}
		int result = a_value + b_value + p[index_p];
		if (result >= 2){     //�п��ܳ���a[i]=1,b[j]=1�ҽ�λҲΪ1�����
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
	//��int���������ת��string
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