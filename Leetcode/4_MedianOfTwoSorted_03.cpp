#include <iostream>
#include <vector>
using namespace std;

//通过
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> temp;
    int i = 0, j = 0;

    //当数组nums1和nums2都不为空时，先加入小的数据，再加入大的数据
    while((i < m) && (j < n)){
        if(nums1[i] <= nums2[j]){
            temp.push_back(nums1[i]);
            ++i;
        }else{
            temp.push_back(nums2[j]);
            ++j;
        }
    }

    //若数组nums1和nums2有一个为空，则不需要判断上述过程，采用下面的解决方法
    //直接将剩余的数组元素添加到temp
    if(i < m){
        for( int k = i; k < m; ++k){
            temp.push_back(nums1[k]);
        }
    }
    if(j < n){
        for( int k = j; k < n; ++k){
            temp.push_back(nums2[k]);
        }
    }

    //对temp数组的大小分奇数和偶数讨论
    if((m+n)%2==1){
        return temp[(m+n-1)/2];
    }else{
        return (temp[(m+n)/2-1]+temp[(m+n)/2])/2.0;
    }
}

int main()
{
    vector<int> nums1, nums2;
    nums1.push_back(2);
    nums1.push_back(3);
    nums2.push_back(6);
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
