#include <iostream>
#include <queue>
using namespace std;

/**
 * BFS的思想
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int findBottomLeftValue(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            int left = 0;
            while(!q.empty()){
                root = q.front();
                q.pop();
                if(root->right){
                    q.push(root->right);
                }
                if(root->left){
                    q.push(root->left);
                }
            }
            return root->val;
        }
};


TreeNode * createBinary(){
    TreeNode *root;
    int data;
    cin >> data;
    if (data == -1){
        root = NULL;
    }
    else{
        root = new TreeNode(data);
        cout << "请输入" << data << "的左节点" << endl;
        root->left = createBinary();
        cout << "请输入" << data << "的右节点" << endl;
        root->right = createBinary();
    }
    return root;
}

int main() {
    TreeNode *root;
    cout << "请输入根节点" << endl;
    root = createBinary();
    Solution solution;
    int res = solution.findBottomLeftValue(root);
    cout << res << endl;
    return 0;
}