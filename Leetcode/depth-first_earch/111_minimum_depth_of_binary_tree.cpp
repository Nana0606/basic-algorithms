#include <iostream>
using namespace std;

/**
 * 思路：
 * 首先判空，若当前结点不存在，直接返回0。
 * 然后看若左子结点不存在，那么对右子结点调用递归函数，并加1返回。
 * 反之，若右子结点不存在，那么对左子结点调用递归函数，并加1返回。
 * 若左右子结点都存在，则分别对左右子结点调用递归函数，将二者中的较小值加1返回即可
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left){
            return 1 + minDepth(root->right);
        }
        if(!root->right){
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

TreeNode* createBinary(){
    int data;
    cin >> data;
    TreeNode *root;
    if (data == -1){
        root = nullptr;
    }else{
        root = new TreeNode(data);
        cout << "请输入" << data << "的左节点!" << endl;
        root->left = createBinary();
        cout << "请输入" << data << "的右节点!" << endl;
        root->right = createBinary();
    }
    return root;
}


int main(){
    TreeNode *root;
    cout << "请输入根节点" << endl;
    root = createBinary();
    Solution solution;
    int res = solution.minDepth(root);
    cout << "结果是：：" << res << endl;
    return 0;
}