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
	int minDepth(TreeNode* root) {
		if (root == NULL){
			return 0;
		}
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (left == 0){   //两个if不太明白
			return right + 1;
		}
		if (right == 0){
			return left + 1;
		}
		return min(left, right) + 1;
	}
};

TreeNode *createBinary(){
	int data;
	cin >> data;
	TreeNode *root;
	if (data == -1){
		root = NULL;
	}
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
	cout << "请输入根节点" << endl;
	root = createBinary();
	Solution solution;
	int res = solution.minDepth(root);
	cout << "结果是：：" << res << endl;
	return 0;
}