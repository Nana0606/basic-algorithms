#include <iostream>
#include <vector>
# include <cmath>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();
    sort(nums.begin(), nums.end());   //����
    if(len == 3)
        return nums[0] + nums[1] + nums[2];   //��ֻ��3��Ԫ�أ�����3��Ԫ�ر������Ԫ��
    else{
        int answer = nums[0] + nums[1] + nums[2];   //����ֵ����������ıȽ�
        int i = 0, j = 0, k = 0, sum = 0;
        for(int i = 0; i < len - 2; ++i){          //���Ƶ�һ��Ԫ�أ������ڵ�һ��Ԫ�ع̶�������£��ڶ����͵�����Ԫ�ص����ȡֵ
            j = i + 1;
            k = len - 1;
            while(j < k){   //������ֹ��������ֹ�ظ�ѭ��
                sum = nums[i] + nums[j] + nums[k];
                if(abs(target - answer) > abs(target - sum)){    //�Ƚ�answerֵ�͵�ǰsum�ĸ���������
                    answer = sum;
                }
                sum < target ? j++ : k--;
            }
        }
        return answer;
    }
}

int main()
{
    int S[] = {0, 2, 1, -3}, target = 1;
    vector<int> nums(S, S+sizeof(S)/sizeof(int));   //vector��ʼ��
    cout << threeSumClosest(nums, target) << endl;
    return 0;
}
