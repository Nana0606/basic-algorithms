# include <iostream>
# include <vector>
# include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root){
			return result;
		}

		//���ע�⣬�ʼ�������root->val��ֵ��ʹ�����þͲ���Ҫ�ٴ���ֵ��
		getBinaryTreePath(result, root, to_string(root->val));
		return result;
	}

	void getBinaryTreePath(vector<string> &result, TreeNode* root, string str){
		if (root->left == NULL && root->right == NULL){
			result.push_back(str);  //��ֹ������Ҫ����result
			return;
		}
		//һ��Ҫ���ж�
		if(root->left)	getBinaryTreePath(result, root->left, str + "->" + to_string(root->left->val));
		if(root->right)	getBinaryTreePath(result, root->right, str + "->" + to_string(root->right->val));
	}
};

TreeNode *createBinary(){
	TreeNode *root;
	int data;
	cin >> data;
	if (data == -1){
		root = NULL;
	}
	else{
		root = new TreeNode(data);
		cout << "������" << data << "����ڵ㣡" << endl;
		root->left = createBinary();
		cout << "������" << data << "���ҽڵ㣡" << endl;
		root->right = createBinary();
	}
	return root;
}


int main(){
	TreeNode *root;
	cout << "��������ڵ㣺��" << endl;
	root = createBinary();
	Solution solution;
	vector<string> result = solution.binaryTreePaths(root);
	for (int i = 0; i < int(result.size()); i++){
		cout << result[i] << endl;
	}
	return 0;
}