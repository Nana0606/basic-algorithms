#include <iostream>
#include <queue>
using namespace std;

/**
 * 思路：
 * 类似宽度搜索的思想：如果2个节点是表亲关系，则2个点一定在某一层，且不是兄弟节点
 * step1：对每一层使用一个queue，存储这层的元素
 * step2：访问队列元素，如果在step1的队列中，也就是这一层的值中找到了2个，则说明是表亲节点或者孩子节点
 * Step3：注意去除兄弟节点的情况。
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = int(q.size());
            bool isXexist = false;
            bool isYexist = false;
            for (int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if (cur->val == x) isXexist = true;
                if(cur->val==y) isYexist = true;
                if(cur->left != NULL && cur->right != NULL){
                    if (cur->left->val==x && cur->right->val==y){
                        return false;  //说明是亲兄妹
                    }
                    if (cur->left->val==y && cur->right->val==x){
                        return false;  //说明是亲兄妹
                    }
                }
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                if(cur->right != NULL){
                    q.push(cur->right);
                }
            }
            if(isXexist && isYexist) return true;
        }
        return false;
    }
};

TreeNode *createBinary(){
    int data;
    cin >> data;
    TreeNode *root;
    if(data == -1) {
        root = NULL;
    }else{
        root = new TreeNode(data);
        cout << "请输入" << data << "的左孩子（-1为空）：\n";
        root->left = createBinary();
        cout << "请输入" << data << "的右孩子（-1为空）：\n";
        root->right = createBinary();
    }
    return root;
}

int main() {
    Solution solution;
    TreeNode * root;
    cout <<"请输入根节点：："<< endl;
    root = createBinary();
    bool res = solution.isCousins(root, 4, 5);
    cout << res << endl;
    return 0;
}