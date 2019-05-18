# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// �Զ���compare����
//bool cmp(int a, int b){
//	return a > b;
//}

//����һ��ֱ�ӵ���algorithm�е�sort�㷨
//int findKthLargest(vector<int>& nums, int k) {
//	sort(nums.begin(), nums.end());
//	return nums[nums.size() - k];
//}

//���������������η���˼��
int findKlargest(vector<int>& nums, int left, int right, int k){
	int i = left, j = right;
	int temp = nums[left];
	if (i > j)
		return -100;
	while (i < j){
		while ((nums[j] <= temp) && (i < j)){
			j--;
		}
		while ((nums[i] >= temp) && (i < j)){
			i++;
		}
		if (i < j){
			swap(nums[i], nums[j]);
		}
	}

	nums[left] = nums[i];   //�������ҵ���Ŧ����ȷλ��
	nums[i] = temp;

	if (i < k - 1){  
		findKlargest(nums, i +1, right, k);
	}
	else if (i > k - 1){
		findKlargest(nums, left, i-1, k);
	} 
	else{   //��i == k-1��˵���ҵ���ȷλ�ö�Ӧ��Ԫ��
		return temp;
	}
}

int findKthLargest(vector<int>& nums, int k){
	int res = findKlargest(nums, 0, nums.size() - 1, k);
	return res;
}

int main(){
	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
	int k = 2;
	int res = findKthLargest(nums, k);
	cout << res << endl;
	return 0;
}