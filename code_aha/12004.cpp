/**
// �����ǶԵģ�����ʱ�䳬ʱ��
# include <iostream>
using namespace std;

struct number{
	long num;   //��ʾ���֣�������1500000000
	int count; //���ֳ��ֵĸ���
};

number* quickSort(number p[], int left, int right){
	int i = left, j = right;
	number temp = p[left];
	if (i > j){
		return p;
	}
	while (i < j){
		while ((p[j].num >= temp.num) && (i < j))
			j--;
		while ((p[i].num <= temp.num) && (i < j))
			i++;
		if (i < j){
			number temp_var = p[i];
			p[i] = p[j];
			p[j] = p[i];
		}
	}//end while, i==j
	p[left] = p[i];
	p[i] = temp;
	quickSort(p, left, i - 1);
	quickSort(p, i + 1, right);
	return p;
}

int main(){
	int n; //����
	cin >> n;
	long value;
	number *p = new number[10000];
	for (int i = 0; i < 10000; i++){
		p[i].num = 0;
		p[i].count = 0;
	}
	int current_index=0;
	for (int i = 0; i < n; i++){
		cin >> value;
		int j = 0;
		for (j = 0; j < current_index; j++){
			if (p[j].num == value) {   // ˵��valueֵ�Ѽ���
				p[j].count++;
				break;
			}
		}
		if (j == current_index){   //˵��û����
			p[current_index].num = value;
			p[current_index].count++;
			current_index += 1;
		}
	} // end for ���ִ���ͳ�����
	p = quickSort(p, 0, current_index - 1);
	for (int i = 0; i <= current_index-1; i++){
		cout << p[i].num << " " << p[i].count << endl;
	}
	return 0;
}
*/

# include <iostream>
# include <map>
using namespace std;

int main(){
	int n; //����
	cin >> n;
	long value;
	map<long, int> num_count_map;
	for (int i = 0; i < n; i++){
		cin >> value;
		if (num_count_map.find(value) == num_count_map.end()){    //û�з���
			num_count_map[value] = 1;
		}
		else{
			num_count_map[value] ++;
		}
	}

	for (map<long, int>::iterator iter = num_count_map.begin(); iter != num_count_map.end(); ++iter){
		cout << iter->first << " " << iter->second << endl;
	}
	return 0;
}