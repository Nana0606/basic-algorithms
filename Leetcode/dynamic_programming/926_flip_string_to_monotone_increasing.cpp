# include <iostream>
# include <string>
using namespace std;


//AC,
//˼·����i=0��i=length()(ע�⣺i=length˵����Ҫ����ȫ����0�����)�����i��¼���ǵ�һ��1��ʼ��λ�ã���Ϊ��һ��1��λ���Ѿ�ȷ�������Կ���i�±�֮ǰ��Ӧ����0��i��i֮���λ�ö���1
//ֻ��Ҫ�滻i֮ǰֵΪ1��Ԫ�أ���i��֮��ֵΪ0��Ԫ�ء�
int minFlipsMonoIncr(string S){
	S += "1";
	int min = INT_MAX;
	//��������i=0�����
	int count = 0;
	for (int k = 0; k < S.length(); k++){
		if (S[k] == '0'){ count++; }
	}
	if (min >= count) min = count;
	count = 0;
	for (int i = 1; i < S.length(); i++){
		for (int j = 0; j < i; j++){
			if (S[j] == '1') count++;
		}
		for (int j = i; j < S.length(); j++){
			if (S[j] == '0') count++;
		}
		if (min >= count) min = count;
		count = 0;
	}
	return min;
}

int main(){
	string s = "00011000";
	int res = minFlipsMonoIncr(s);
	cout << res << endl;
	return 0;
}