# include <iostream>
# include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		int sum = 0;
		int res = intraverse(root, L, R, sum);
		return res;
	}

	//���������ע��ע�⣺��������Ľ���������
	int intraverse(TreeNode* root, int L, int R, int sum){
		if (root){
			sum = intraverse(root->left, L, R, sum);
			if (root->val >= L && root->val <= R){
				sum += root->val;
			}
			sum = intraverse(root->right, L, R, sum);
		}
		return sum;
	}

};

TreeNode * createBinary(){
	TreeNode *root;
	int data;
	cin >> data;
	if (data == -1){
		root = NULL;
	}
	else{
		root = new TreeNode(data);
		cout << "������" << data << "�����ӽ�㣨-1��ʾ�գ�!" << endl;
		root->left = createBinary();
		cout << "������" << data << "���Һ��ӽ�㣨-1��ʾ�գ�!" << endl;
		root->right = createBinary();
	}
	return root;
}

int main(){
	TreeNode *root;
	cout << "����������" << endl;
	root = createBinary();
	Solution solution;
	int L = 7, R = 15;
	int res = solution.rangeSumBST(root, L, R);
	cout << res << endl;
	return 0;
}