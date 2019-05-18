# include <iostream>
# include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		if (left == 0) return right + 1;   //求最大值，若是左边为0，则取右边（因为右边可能比左边高度大）
		else if (right == 0) return left + 1;
		else {
			return max(left, right) + 1;
		}
	}
};

TreeNode *createBinary(){
	int data;
	cin >> data;
	TreeNode *root;
	if (data == -1) root = NULL;
	else{
		root = new TreeNode(data);
		cout << "请输入" << data << "的左节点（-1表示为空）" << endl;
		root->left = createBinary();
		cout << "请输入" << data << "的右节点（-1表示为空）" << endl;
		root->right = createBinary();
	}
	return root;
}

int main(){
	TreeNode * root;
	cout << "请输入根节点" << endl;
	root = createBinary();

}