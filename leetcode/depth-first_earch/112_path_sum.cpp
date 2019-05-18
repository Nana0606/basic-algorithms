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
		cout << "������" << data << "����ڵ㣨-1��ʾ�գ�" << endl;
		root->left = createBinary();
		cout << "������" << data << "���ҽڵ㣨-1��ʾ�գ�" << endl;
		root->right = createBinary();
	}
	return root;
}

int main(){
	TreeNode *root;
	cout << "��������ڵ㣺��" << endl;
	root = createBinary();
	Solution solution;
	int sum;
	cout << "������sum::" << endl;
	cin >> sum;
	bool res = solution.hasPathSum(root, sum);
	cout << res << endl;
	return 0;
}