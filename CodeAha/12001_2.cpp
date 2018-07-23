# include <iostream>
using namespace std;

int* quick_sort(int p[], int left, int right){
	int i = left, j = right;
	int temp = p[left];  //最左边的元素，当做一个枢纽点
	if (i > j)
		return p;
	while (i < j){
		while ((p[j]>=temp) && (i < j))
			j--;   //一定要先从j开始，即从最右边开始
		while ((p[i] <= temp) && (i < j))
			i++;
		if (i < j){
			swap(p[i], p[j]);  //左边找到一个大的，右边找到一个小的，替换
		}
	}// end while, i=j
	//下面将i=j时的元素值和枢纽值交换
	p[left] = p[i];
	p[i] = temp;
	quick_sort(p, left, i - 1);
	quick_sort(p, j + 1, right);
	return p;
}

int main(){
	int n; //n表示输入数据的个数
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}
	int count = 1;    //第一个数字一定是不重复的。
	p = quick_sort(p, 0, n - 1);
	for (int i = 0; i < n-1; i++){
		if (p[i] != p[i + 1]){     //说明当前值和前一个数据不重复
			count++;    //统计不重复的数目
		}
	}
	cout << count << endl;
	cout << p[0] << " ";    //输出第一个值
	for (int i = 0; i < n - 1; i++){    //将不重复的数据输出
		if (p[i] != p[i + 1]){
			cout << p[i + 1] << " ";
		}
	}
	cout << endl;
	return 0;
}