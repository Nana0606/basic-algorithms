# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

//��Ŀ�����������
//��ַ��https://www.nowcoder.com/question/next?pid=4998655&qid=95826&tid=20642690

int main(){
	int N;
	cin >> N;
	int len_N = N;
	int value;
	vector<int> vec;
	while (N-- > 0){
		cin >> value;
		vec.push_back(value);
	}
	vector<int> vec_unsorted = vec;
	sort(vec.begin(), vec.end());
	int res = 0;   //res������¼�ж���Ԫ�ر������������յ�λ����
	int j = 0;
	for (int i_unsort = 0; i_unsort < len_N; i_unsort++){
		if (vec_unsorted[i_unsort] == vec[j]){
			j++;
			res++;
		}
	}
	cout << len_N - res << endl;
	return 0;
}