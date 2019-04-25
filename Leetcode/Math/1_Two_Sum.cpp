#include <iostream>
#include <vector>

using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        for (int i = 0; i < nums.size();++i){
            for(int j = 0; j < nums.size(); ++j){
                if(nums.at(i) + nums.at(j) == target){
                    index.push_back(i);
                    index.push_back(j);
                    return index;
                }
            }
        }
        return index;
    }

int main()
{
    int *numbers = new int[]£»
    numbers = {2, 7, 11, 15};
    vector<int> nums(numbers, numbers+(int)numbers.size());
    for(int i = 0; i< (int)numbers.size(); ++i){
        nums.push_back(numbers[i]);
    }
    int target = 9;
    cout<<twoSum(nums, target)<<endl;
    return 0;
}
