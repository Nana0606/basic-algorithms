#include <iostream>
using namespace std;

/**
 * 思路：参考剑指offer第240页
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <=0) return 0;
        if (n==1) return 1;
        int* dp = new int[n];
        int t2 =0,t3=0,t5=0;
        dp[0] = 1;
        for(int i = 1; i <n;i++){
            dp[i] = min(dp[t2] * 2, min(dp[t3]*3, dp[t5]*5));
            if(dp[i] == dp[t2] * 2) t2++;
            if(dp[i] == dp[t3] * 3) t3++;
            if(dp[i] == dp[t5] * 5) t5++;
          }
        return dp[n-1];
    }
};


int main() {
    Solution solution;
    int res = solution.nthUglyNumber(10);
    cout << res << endl;
    return 0;
}