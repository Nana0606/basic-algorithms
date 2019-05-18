# include <iostream>
# include <set>
# include <vector>
using namespace std;

//����һ������set������
/*
int findDuplicate(vector<int>& nums) {
	set<int> temp;
	for (int i = 0; i < int(nums.size()); i++){
		temp.insert(nums[i]);
		if (int(temp.size()) < (i + 1)) return nums[i];
	}
	return 0;
}
*/

//�����ظ�Ԫ�ش����ķ���Ԫ�ص�ѭ����
int findDuplicate(vector<int>& nums){
	int slow = nums[0];  //slow��ʼ���ǵ�һ��Ԫ��
	int fast = nums[nums[0]];  //fast��ʼ�ĵڶ���Ԫ��

	//��һ��ѭ����Ϊ���ҵ�һ��ѭ���壬slow==fast����������һ���ڻ��е�ĳһ��λ���ϡ�
	while (slow != fast){
		slow = nums[slow];
		fast = nums[nums[fast]];
	}

	//�ڶ���ѭ����Ϊ���ҵ��ظ�Ԫ�أ�Ҳ����ѭ����Ŀ�ʼ
	fast = 0;  // fast��ʼ��ͷ��ʼȥ����
	while (slow != fast){
		fast = nums[fast];
		slow = nums[slow];
	}
	return slow;
}


int main(){
	vector<int> nums = { 1, 3, 4, 2, 2};
	int res = findDuplicate(nums);
	cout << res << endl;
	return 0;
}