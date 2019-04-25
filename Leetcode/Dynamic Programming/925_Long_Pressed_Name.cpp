# include <iostream>
# include <string>
# include <utility>
# include <vector>
using namespace std;

// ����һ��AC����Ҫ˼·��ʹ��ָ������Ƶ���������������кܶ��жϣ����ԱȽ����׳����⡣
/*
bool isLongPressedName(string name, string typed){
	int tempi = 0;
	int tempj = 0;
	if (name[0] != typed[0]) return false;
	while (tempi < int(name.length()) && tempj < int(typed.length())){
		while (name[tempi] == typed[tempj] && tempi < int(name.length()) && tempj < int(typed.length())){
			cout << "1: " << tempi << " " << tempj << endl;
			tempi++; tempj++; 
		}
		if (name[tempi] != typed[tempj]){
			if (name[tempi] != name[tempi - 1]){
				if (typed[tempj] != name[tempi - 1]) return false;
				while (typed[tempj] == name[tempi - 1] && tempi < int(name.length()) && tempj < int(typed.length())){ tempj++; }
				cout << "2: " << tempi << " " << tempj << endl;
			}
			else return false;
		}
	}	
	if (tempi <= int(name.length()) - 1) return false;
	if (tempj <= int(typed.length()) - 1){
		for (int t = tempj; t < int(typed.length()); t++){
			if (typed[tempj] != name[name.length() - 1]) return false;
		}
	}
	return true;
}
*/

//��������AC����Ҫ˼·��ʹ���������μ�¼���ֵ�ֵ�������ִ�������ע��Ҫ���򣩣����Ƚ����ݵĴ�С
vector<pair<char, int> > count_num(string s){
	vector<pair<char, int> > res;
	pair<char, int> name_pair;
	char temp_char = s[0];
	name_pair = make_pair(temp_char, 1);
	for (int i = 1; i < s.length(); i++){
		if (s[i] == temp_char){
			name_pair.second += 1;
		}
		else{
			res.push_back(name_pair);
			temp_char = s[i];
			name_pair = make_pair(temp_char, 1);
		}
	}
	res.push_back(name_pair);
	return res;
}

bool isLongPressedName(string name, string typed){
	vector<pair<char, int> > name_vec;
	vector<pair<char, int> > typed_vec;
	name_vec = count_num(name);
	typed_vec = count_num(typed);
	if (int(name_vec.size()) != int(typed_vec.size())){
		return false;
	}
	for (int i = 0; i < int(name_vec.size()); i++){
		if (name_vec[i].second > typed_vec[i].second){
			return false;
		}
	}
	return true;
}

int main(){
	string s1 = "leelees";
	string s2 = "lleeelee";
	bool res = isLongPressedName(s1, s2);
	cout << res << endl;
	return 0;
}