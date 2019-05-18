# include <iostream>
# include <algorithm>
# include <map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rob(TreeNode* root) {
		map<TreeNode*, int> map_val;
		return robByMap(root, map_val);
	}

	int robByMap(TreeNode* root, map<TreeNode*, int> map_val){
		if (root == nullptr) return 0;

		map<TreeNode*, int>::iterator it = map_val.find(root);
		if (it != map_val.end()){  //说明已经map_val中
			cout << "在map中" << endl;
			return it->second;  // it->first获取TreeNode类型，it->second获取int类型
		}

		int val = 0;
		if (root->left != nullptr){
			val += rob(root->left->left) + rob(root->left->right);
		}
		if (root->right != nullptr){
			val += rob(root->right->left) + rob(root->right->right);
		}

		//分两种情况：1、当前root节点被偷，则当前节点，和孩子的孩子可以同时被偷
		//2、当前root不被偷，则孩子节点被偷
		val = max(root->val + val, rob(root->left) + rob(root->right));
		map_val.insert(pair<TreeNode*, int>(root, val));
		return val;
	}
};

TreeNode *createBinary(){
	TreeNode * root;
	int data;
	cin >> data;
	if (data == -1){
		root = nullptr;
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
	int res = solution.rob(root);
	cout << res << endl; 
	return 0;
}