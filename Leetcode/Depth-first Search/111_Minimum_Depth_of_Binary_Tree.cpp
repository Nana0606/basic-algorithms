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
		if (left == 0){   //����if��̫����
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
		cout << "������" << data << "����ڵ㣨-1��ʾ�գ�" << endl;
		root->left = createBinary();
		cout << "������" << data << "���ҽڵ㣨-1��ʾ�գ�" << endl;
		root->right = createBinary();
	}
	return root;
}

int main(){
	TreeNode *root;
	cout << "��������ڵ�" << endl;
	root = createBinary();
	Solution solution;
	int res = solution.minDepth(root);
	cout << "����ǣ���" << res << endl;
	return 0;
}