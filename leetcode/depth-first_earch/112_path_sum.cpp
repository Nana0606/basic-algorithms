# include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL) return false;
		if (root->val == sum && root->left == NULL && root->right == NULL) return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

TreeNode *createBinary(){
	int data;
	cin >> data;
	TreeNode * root;
	if (data == -1) root = NULL;
	else{
		root = new TreeNode(data);
		cout << "请输入" << data << "的左节点（-1表示空）" << endl;
		root->left = createBinary();
		cout << "请输入" << data << "的右节点（-1表示空）" << endl;
		root->right = createBinary();
	}
	return root;
}

int main(){
	TreeNode *root;
	cout << "请输入根节点：：" << endl;
	root = createBinary();
	Solution solution;
	int sum;
	cout << "请输入sum::" << endl;
	cin >> sum;
	bool res = solution.hasPathSum(root, sum);
	cout << res << endl;
	return 0;
}