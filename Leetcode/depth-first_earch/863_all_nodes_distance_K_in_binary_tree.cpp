#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/**
 * 思路：
 * Step1: 先找到所有的(son,parent)节点
 * Step2: 使用dfs寻找与节点距离为K的点（普通的向下dfs只能找到距离为5的子节点，但是可能出现经过父节点不断走的K距离，所以才引入(son,parent)节点）
 *          也就是除了普通的dfs之外，加了TreeNode *p = parent[node]; if(p){dfs(p, K-1);}这部分内容（功能是向父节点方向查询）
 *
 *
 * 注意：下面程序的输入有些问题，实际上在执行的时候，target是root树的一个节点，而不是一棵单独的树
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> ans;
    map<TreeNode*, TreeNode*> parent;  // son=>parent
    set<TreeNode*> visit;     //record visied node

    //寻找son-parent pair
    void findParent(TreeNode* node){
        if(!node) return;
        if(node->left){
            parent[node->left] = node;
            findParent(node->left);
        }
        if(node->right) {
            parent[node->right] = node;
            findParent(node->right);
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root) return {};
        findParent(root);
        cout << "find root:" << parent.size() << endl;
        dfs(target, K);
        return ans;
    }


    void dfs(TreeNode *node, int K){
        if(visit.find(node) != visit.end()){
            return;
        }
        visit.insert(node);
        if(K==0){
            ans.push_back(node->val);
            return;
        }
        if(node->left){
            dfs(node->left, K-1);
        }
        if(node->right){
            dfs(node->right, K-1);
        }

        //上面都是普通的dfs，下面是为了向父节点方向查询
        TreeNode *p = parent[node];
        if(p){
            dfs(p, K-1);
        }
    }
};

TreeNode *createBinary(){
    TreeNode * root;
    int data;
    cin >> data;
    if(data == -1){
        root = NULL;
    }else{
        root = new TreeNode(data);
        cout << "请输入" <<data << "的左节点" << endl;
        root->left = createBinary();
        cout << "请输入" <<data << "的右节点" << endl;
        root->right = createBinary();
    }
    return root;
}

int main() {
    TreeNode *root, * target;
    cout << "请输入root根节点" << endl;
    root= createBinary();
    cout << "请输入target根节点" << endl;
    target = createBinary();
    Solution solution;
    vector<int> res = solution.distanceK(root, target, 2);
    for(int elem: res){
        cout << elem << endl;
    }
    return 0;
}