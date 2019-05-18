#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int count = nums.size();
    vector<int>::iterator it = nums.begin();
    while(it != nums.end()){
        if(*it == val){
            it = nums.erase(it);
            -- count;
        }else{
            ++it;
        }
    }
    for (int j = 0; j < nums.size(); ++j){
        cout << nums[j] << " ";
    }
    cout << endl;
    return count;
}

int main()
{
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(3);
    int replaced = 3;
    cout << removeElement(temp, replaced) << endl;
    return 0;
}
