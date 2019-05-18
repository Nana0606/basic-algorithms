# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	bool isBalanced(TreeNode* root) {
		if (balancedHeight(root) == -1){
			return false;
		}
		else{
			return true;
		}
	}
private:
	//如果是平衡二叉树返回该二叉树的高度，否则返回-1
	int balancedHeight(TreeNode *node){
		if (node == NULL){
			return 0;
		}//if
		//左子树高度
		int left = balancedHeight(node->left);
		//右子树高度
		int right = balancedHeight(node->right);
		//左右子树高度差不超过1
		if (abs(left - right) > 1 || left < 0 || right < 0){
			//-1表示不满足平衡二叉树的要求
			return -1;
		}//if
		return max(left, right) + 1;
	}
};

//创建二叉树
TreeNode* createBinaryTree(){
	int data;
	cin >> data;
	TreeNode *root;
	if (data == -1){
		root = NULL;
	}
	else{
		root = new TreeNode(data);
		cout << "请输入" << data << "的左孩子(-1为空):\n";
		root->left = createBinaryTree();
		cout << "测试" << root->val << endl;
		cout << "请输入" << data << "的右孩子(-1为空)\n";
		root->right = createBinaryTree();
	}
	return root;
}

int main(){
	Solution solution;
	TreeNode* root;
	cout << "请输入根节点:\n";
	root = createBinaryTree();
	bool res = solution.isBalanced(root);
	cout << "结果是：：" << res << endl;
	return 0;
}