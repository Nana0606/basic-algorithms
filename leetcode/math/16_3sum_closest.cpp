#include <iostream>
#include <vector>
# include <cmath>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();
    sort(nums.begin(), nums.end());   //排序
    if(len == 3)
        return nums[0] + nums[1] + nums[2];   //若只有3个元素，则这3个元素便是最佳元素
    else{
        int answer = nums[0] + nums[1] + nums[2];   //赋初值，用于下面的比较
        int i = 0, j = 0, k = 0, sum = 0;
        for(int i = 0; i < len - 2; ++i){          //控制第一个元素，查找在第一个元素固定的情况下，第二个和第三个元素的最佳取值
            j = i + 1;
            k = len - 1;
            while(j < k){   //设置终止条件，防止重复循环
                sum = nums[i] + nums[j] + nums[k];
                if(abs(target - answer) > abs(target - sum)){    //比较answer值和当前sum哪个更合题意
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
    vector<int> nums(S, S+sizeof(S)/sizeof(int));   //vector初始化
    cout << threeSumClosest(nums, target) << endl;
    return 0;
}
