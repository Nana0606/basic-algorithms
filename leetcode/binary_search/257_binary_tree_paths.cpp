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

		//这个注意，最开始传输的是root->val的值。使用引用就不需要再传输值了
		getBinaryTreePath(result, root, to_string(root->val));
		return result;
	}

	void getBinaryTreePath(vector<string> &result, TreeNode* root, string str){
		if (root->left == NULL && root->right == NULL){
			result.push_back(str);  //终止条件，要放入result
			return;
		}
		//一定要有判断
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
		cout << "请输入" << data << "的左节点！" << endl;
		root->left = createBinary();
		cout << "请输入" << data << "的右节点！" << endl;
		root->right = createBinary();
	}
	return root;
}


int main(){
	TreeNode *root;
	cout << "请输入根节点：：" << endl;
	root = createBinary();
	Solution solution;
	vector<string> result = solution.binaryTreePaths(root);
	for (int i = 0; i < int(result.size()); i++){
		cout << result[i] << endl;
	}
	return 0;
}