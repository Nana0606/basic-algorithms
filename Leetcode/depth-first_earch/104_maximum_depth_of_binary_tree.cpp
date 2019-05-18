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
		if (left == 0) return right + 1;   //�����ֵ���������Ϊ0����ȡ�ұߣ���Ϊ�ұ߿��ܱ���߸߶ȴ�
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
		cout << "������" << data << "����ڵ㣨-1��ʾΪ�գ�" << endl;
		root->left = createBinary();
		cout << "������" << data << "���ҽڵ㣨-1��ʾΪ�գ�" << endl;
		root->right = createBinary();
	}
	return root;
}

int main(){
	TreeNode * root;
	cout << "��������ڵ�" << endl;
	root = createBinary();

}