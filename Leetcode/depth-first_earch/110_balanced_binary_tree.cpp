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
	//�����ƽ����������ظö������ĸ߶ȣ����򷵻�-1
	int balancedHeight(TreeNode *node){
		if (node == NULL){
			return 0;
		}//if
		//�������߶�
		int left = balancedHeight(node->left);
		//�������߶�
		int right = balancedHeight(node->right);
		//���������߶Ȳ����1
		if (abs(left - right) > 1 || left < 0 || right < 0){
			//-1��ʾ������ƽ���������Ҫ��
			return -1;
		}//if
		return max(left, right) + 1;
	}
};

//����������
TreeNode* createBinaryTree(){
	int data;
	cin >> data;
	TreeNode *root;
	if (data == -1){
		root = NULL;
	}
	else{
		root = new TreeNode(data);
		cout << "������" << data << "������(-1Ϊ��):\n";
		root->left = createBinaryTree();
		cout << "����" << root->val << endl;
		cout << "������" << data << "���Һ���(-1Ϊ��)\n";
		root->right = createBinaryTree();
	}
	return root;
}

int main(){
	Solution solution;
	TreeNode* root;
	cout << "��������ڵ�:\n";
	root = createBinaryTree();
	bool res = solution.isBalanced(root);
	cout << "����ǣ���" << res << endl;
	return 0;
}