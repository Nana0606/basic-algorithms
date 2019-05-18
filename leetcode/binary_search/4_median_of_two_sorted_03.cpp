#include <iostream>
#include <vector>
using namespace std;

//ͨ��
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> temp;
    int i = 0, j = 0;

    //������nums1��nums2����Ϊ��ʱ���ȼ���С�����ݣ��ټ���������
    while((i < m) && (j < n)){
        if(nums1[i] <= nums2[j]){
            temp.push_back(nums1[i]);
            ++i;
        }else{
            temp.push_back(nums2[j]);
            ++j;
        }
    }

    //������nums1��nums2��һ��Ϊ�գ�����Ҫ�ж��������̣���������Ľ������
    //ֱ�ӽ�ʣ�������Ԫ����ӵ�temp
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

    //��temp����Ĵ�С��������ż������
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
