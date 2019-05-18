# include <iostream>
# include <string>
using namespace std;

string longestPalindrome(string s) {
	if (s.size() <= 1)    
		return s;
	int mid = 0;
	int max_len = 0;
	int min_start = 0;
	for (mid = 0; mid < s.size();){   //mid��ʾ�����ַ����м�Ĳ��֣�˼���ǹ̶��м�ֵ
		if (s.size() - mid <= max_len / 2)   //�������б�max_len������������
			break;
		int start = mid;
		int end = mid;
		while (end < s.size() && s[end] == s[end + 1])   //�����ַ����м��л������У������۶��ٸ���ͬ��Ԫ�أ�����Ӱ�����ǻ������У��һ������г��ȱ䳤
			end++;
		mid = end + 1;   // ��Ϊ�������б䳤�������м�ֵ��Ҫ���ӣ���start���䣬�����м���ͬ��Ԫ������������ż������û��Ӱ��
		while (end < s.size() - 1 && start > 0 && s[start - 1] == s[end + 1]){
			start--;
			end++;
		}
		int len = end - start + 1;
		if (max_len < len){
			min_start = start;
			max_len = len;
		}
	}
	return s.substr(min_start, max_len);
}

int main(){
	string str;
	cin >> str;
	cout << longestPalindrome(str) << endl;
	return 0;
}