# include <iostream>
# include <vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
	/**
	�����ö��ֲ��Ҷ�λ����λ�ã��ٸ���target��С��ΧԪ�صĴ�С��ϵ��ϸ��λ��
	*/
	int left = 0;
	int right = nums.size() - 1;
	
	while (left < right - 1){    //���ֲ���
		int mid = (left + right) / 2;
		if (nums[mid] == target){
			return mid;
		}
		else if (target > nums[mid]){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	if (left == right){    //��left >= right - 1ʱ�����ܳ�����߽���Ȼ���û�в��ҵ�Ԫ�ص����
		if (target == nums[left]){    //��߽����
			return left;
		}
		else{     //��߽粻��
			return target > nums[left] ? (right + 1) : left;
		}
	}
	else if (left == right - 1){
		if (target == nums[left]){   //����߽����
			return left;
		}
		else if (target == nums[right]){    //���ұ߽����
			return right;
		}
		else if (target < nums[left]){    //����߽�С
			return left;
		}
		else if (target > nums[right]){    //���ұ߽��
			return right+1;
		}
		else{     //������߽���ұ߽��м�
			return left + 1;
		}
	}
}

int main(){
	vector<int> nums = { 1, 2, 4, 6, 7};
	int target = 8;
	int result = searchInsert(nums, target);
	cout << result << endl;
	return 0;
}