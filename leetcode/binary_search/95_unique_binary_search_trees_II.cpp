# include <iostream>
# include <vector>
using namespace std;

//使用递归的思路：因为BST是保证前序遍历结果是符合顺序的。所以如果跟节点是i，则左子树的节点是0~(i-1)，右子树的节点是(i+1)~n。对于左子树/右子树也是同样的操作

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> vec;
		if (n == 0) return vec;
		return genTrees(1, n);
	}

	vector<TreeNode*> genTrees(int start, int end){

		vector<TreeNode*> vec;

		if (start > end){
			vec.push_back(NULL);
			return vec;
		}

		if (start == end){
			vec.push_back(new TreeNode(start));
			return vec;
		}

		vector<TreeNode*> left, right;
		for (int i = start; i <= end; i++){
			left = genTrees(start, i - 1);
			right = genTrees(i + 1, end);

			for (TreeNode* lnode : left){
				for (TreeNode* rnode : right){
					TreeNode* root = new TreeNode(i);
					root->left = lnode;
					root->right = rnode;
					vec.push_back(root);
				}
			}
		}
		return vec;
	}
	void preTraverse(TreeNode *root)//前序
	{
		if (root)
		{
			cout << root->val << "   ";
			preTraverse(root->left);
			preTraverse(root->right);
		}
	}
};

int main(){
	Solution solution;
	vector<TreeNode*> res = solution.generateTrees(3);
	for (TreeNode* node : res){
		solution.preTraverse(node);
	}
	return 0;
}