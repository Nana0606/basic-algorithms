# include <iostream>
# include <sstream>
# include <string>
# include <vector>
#include <unordered_map>
using namespace std;

//��Ҫ˼�룬�������ת��Ϊ��2���ַ����У����۸��Գ����˶��ٴΣ�����ֻҪ������1�ε��ַ��������
//ע����ʵ�֣�
vector<string> uncommonFromSentences(string A, string B) {
	vector<string> res;
	unordered_map<string, int> counter;
	istringstream iss(A + " " + B);  //�����Զ��Կո�Ϊ�ָ���
	while (iss >> A){
		counter[A]++;    //map
	}
	for (auto w : counter){
		if (w.second == 1) res.push_back(w.first);
	}
	return res;
}

int main(){
	string A = "this apple is sweet";
	string B = "this apple is sour";
	vector<string> res;
	res = uncommonFromSentences(A, B);
	for (int i = 0; i<int(res.size()); i++){
		cout << res[i] << endl;
	}
	return 0;
}
