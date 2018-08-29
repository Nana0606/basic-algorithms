#include <iostream>
#include <vector>
using namespace std;

//ͨ��

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();

    //�������������Ǳ�֤����nums1�Ƕ̵��Ǹ�����nums2�ǳ����Ǹ�
    vector<int> tempArr;
    int temp;
    if(m > n){
        tempArr = nums1;
        nums1 = nums2;
        nums2 = tempArr;
        temp = m;
        m = n;
        n = temp;
    }

    int imin = 0, imax = m, half_len=(m+n+1)/2, max_of_left, min_of_right, i, j;

    while(imin <= imax){
        i = (imin + imax)/2;  //iʹ�ö��ַ���˼��
        j = half_len - i;  //j�ĸ�������
        if((i < m) && (nums2[j-1] > nums1[i])){  //�Ǳ߽����
            imin = i + 1;
        }else if((i > 0) && (nums1[i-1] > nums2[j])){   //�Ǳ߽����
            imax = i - 1;
        }else{
            //���Ǳ߽����
            if(i==0){
                max_of_left = nums2[j-1];
            }else if( j == 0){
                max_of_left = nums1[i-1];
            }else{
                max_of_left = max(nums1[i-1], nums2[j-1]);
            }

            if((m+n)%2==1){   //��������
                return max_of_left;
            }

            if(i==m){  //ż������
                min_of_right = nums2[j];
            }else if(j ==n ){
                min_of_right = nums1[i];
            }else{
                min_of_right = min(nums1[i], nums2[j]);
            }
            return (max_of_left + min_of_right)/2.0;
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
