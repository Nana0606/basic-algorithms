#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string smallestFromLeaf(TreeNode* root, string s="") {
        /**
         * 思路：我们仍然采用从root->leaf的思路，但是为了得到最小的revered的string，我们需要从root不断寻找较小的节点
         * trick：忽略到只有一个孩子的非叶子节点，To do that, we can return "|", which is larger than 'z'.
         */
        if (root == NULL)  return "|";
        s = string(1, 'a' + root->val) + s;  //这里是新节点在前面，即从叶子->根。
        if(root->left == root->right)   //说明root->left = null and root->right = null.
            return s;
        else{
            return min(smallestFromLeaf(root->left, s), smallestFromLeaf(root->right, s));
        }

    }
};


TreeNode * createBinary(){
    TreeNode *root;
    int data;
    cin >> data;
    if (data == -1) root=NULL;
    else{
        root = new TreeNode(data);
        cout << "请输入" << data << "的左节点（-1作为结束）" << endl;
        root->left = createBinary();
        cout << "请输入" << data << "的右节点（-1作为结束）" << endl;
        root->right = createBinary();
    }
    return root;
}

int main() {
    TreeNode * root;
    cout << "请输入根节点" << endl;
    root = createBinary();
    Solution solution;
    string res = solution.smallestFromLeaf(root);
    cout << res << endl;
    return 0;
}