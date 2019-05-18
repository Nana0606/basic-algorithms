# include <iostream>
# include <vector>
using namespace std;

//ʹ�õݹ��˼·����ΪBST�Ǳ�֤ǰ���������Ƿ���˳��ġ�����������ڵ���i�����������Ľڵ���0~(i-1)���������Ľڵ���(i+1)~n������������/������Ҳ��ͬ���Ĳ���

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
	void preTraverse(TreeNode *root)//ǰ��
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