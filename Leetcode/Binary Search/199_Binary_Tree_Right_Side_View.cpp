#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightView(root, result, 0);
        return result;
    }

    void rightView(TreeNode* curr, vector<int> &result, int curDepth){
        if (curr == NULL){
            return;
        }
        if(curDepth == result.size()){
            result.push_back(curr->val);
        }
        rightView(curr->right, result, curDepth + 1);
        rightView(curr->left, result, curDepth + 1);
    }
};


TreeNode* createBinary(){
    TreeNode * root;
    int data;
    cin >> data;
    if (data == -1) {
        root = NULL;
    }
    else{
        root = new TreeNode(data);
        cout << "请输入" << data << "的左节点!" << endl;
        root->left = createBinary();
        cout << "请输入" << data << "的右节点！" << endl;
        root->right = createBinary();
    }
    return root;
}


int main() {
    TreeNode *root;
    cout << "请输入根节点" << endl;
    root = createBinary();
    Solution solution;
    vector<int> res= solution.rightSideView(root);
    for(int i = 0; i < int(res.size()); i++){
        cout << res[i] << endl;
    }
    return 0;
}