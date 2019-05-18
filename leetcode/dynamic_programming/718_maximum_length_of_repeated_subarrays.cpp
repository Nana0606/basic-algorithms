#include <iostream>
#include <vector>
using namespace std;

/**
 * 思想和最长公共子串是一样的。
 * dp[i][j]表示A[0,...,i-1]和B[0,...,j-1]的公共子串长度
 * 初始化：dp[0][i] = 0;dp[0][j] = 0;
 * 更新函数：
 *      若A[i-1] == B[j-1]，则dp[i][j] = dp[i-1][j-1] + 1
 *      否则：dp[i][j] = 0
 * 选择策略：
 *      因为dp[i][j]都有可能成为最大的值，所以需要在所有dp[i][j]的结果中找最大的值。
 */


class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int max_value = 0;
        int ** dp = new int*[int(A.size()) + 1];
        for (int i = 0; i < (int)A.size() + 1; i++) {
            dp[i] = new int[int(B.size()) + 1];
            dp[i][0] = 0;
        }
        for (int j =0; j < int(B.size()) + 1; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i < int(A.size()) + 1; i++){
            for(int j =1; j < int(B.size()) + 1; j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = 0;
                }
                if(max_value < dp[i][j]){
                    max_value = dp[i][j];
                }
            }
        }
        for(int i =0; i < int(A.size()) + 1; i++){
            delete[] dp[i];
        }
        delete[] dp;
        return max_value;
    }
};

int main() {
    vector<int> A = {1, 2, 3, 2, 1};
    vector<int> B = {3, 2, 1, 4, 7};
    Solution solution;
    int res = solution.findLength(A, B);
    cout << res << endl;
    return 0;
}