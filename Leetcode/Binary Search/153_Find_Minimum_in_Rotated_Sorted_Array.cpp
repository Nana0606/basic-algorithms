# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// ���εĶ��ֲ��ң�����nums[mid] > first_value����������Ϊ���ֲ��ҵ���ֹ�㣬�����ض��ֲ��ҵķ�Χ
vector<int> binary_search(vector<int>& nums, int left, int right, int first_value){
	//���ֲ��ҵ�˼��
	int mid = (left + right) / 2;
	vector<int> result;
	while (left < right && nums[mid] > first_value){
		left = mid + 1;
		mid = (left + right) / 2;
	}

	result.push_back(left);
	result.push_back(right);
	return result;
}

int findMin(vector<int>& nums) {
	//ʹ�ö��ֲ��ҽ���Сֵ��С����һ����Χ�ڣ��������Χ�ڱ����ҵ���Сֵ
	int first_value = nums[0];
	vector<int> result = binary_search(nums, 0, int(nums.size()) - 1, first_value);

	int min_value = min(nums[result[0]], first_value);    //�п�������ȫ�����һ�����У���δ�з�ת�Ĳ��֡�
	for (int i = result[0] + 1; i <= result[1]; i++){
		min_value = min(min_value, nums[i]);
	}
	return min_value;
}

int main(){
	vector<int> nums = { 1, 2, 3 };
	int min = findMin(nums);
	cout << min << endl;
	return 0;
}