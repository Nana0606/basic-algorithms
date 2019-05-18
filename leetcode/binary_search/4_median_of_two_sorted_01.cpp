#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//超时

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    //若len1+len2是奇数，则舍掉前面(len1+len2-1)/2个数即可
    //若len2+len是偶数，则舍掉前面（len2+len）/2-1个数即可
    int count = 0; //用于统计已经舍弃的元素个数
    int tempa = 0, tempb = 0;
    if((len1+len2)%2 == 1){

        while(((tempa < len1) || (tempb < len2)) && (count < ((len1+len2-1)/2))){
            if(nums1[tempa] <= nums2[tempb]){
                tempa += 1;
                count ++;
            }else{
                tempb +=1;
                count ++;
            }
        }
        return nums1[tempa] < nums2[tempb] ? nums1[tempa] : nums2[tempb];
    }
    else{
         while(((tempa < len1) || (tempb < len2)) && (count < ((len1+len2)/2-1))){
            if(nums1[tempa] <= nums2[tempb]){
                tempa += 1;
                count ++;
            }else{
                tempb +=1;
                count ++;
            }
        }
        if((tempa == len1)||(tempb == len2)){
            return (tempa==len1) ? ((nums2[tempb]+nums2[tempb+1])*1.0/2.0) : ((nums1[tempa]+nums1[tempa+1])*1.0/2.0) ;
        }else if(tempa == (len1-1)){
            vector<int> temp;
            temp.push_back(nums1[tempa]);
            temp.push_back(nums2[tempb]);
            temp.push_back(nums2[tempb]+1);
            sort(temp.begin(), temp.end());
            return (temp[0]+temp[1])*1.0/2.0;
        }else if(tempb == (len2-1)){
            vector<int> temp;
            temp.push_back(nums1[tempa]);
            temp.push_back(nums1[tempa+1]);
            temp.push_back(nums2[tempb]);
            sort(temp.begin(), temp.end());
            return (temp[0]+temp[1])*1.0/2.0;
        }
        else{
            vector<int> temp;
            temp.push_back(nums1[tempa]);
            temp.push_back(nums1[tempa+1]);
            temp.push_back(nums2[tempb]);
            temp.push_back(nums2[tempb]+1);
            sort(temp.begin(), temp.end());
            return (temp[0]+temp[1])*1.0/2.0;
        }
    }
}

int main()
{
    vector<int> nums1, nums2;
    nums1.push_back(2);
    nums1.push_back(3);
    nums2.push_back(1);
    nums2.push_back(6);
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
