# include <iostream>
# include <vector>
# include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) return NULL;
		else{
			int mid = int(nums.size()) / 2;
			TreeNode * root = new TreeNode(nums[mid]);
			
			//以下创建方法是可行的，最后分开的要么两边长度相等，要不就是右边比左边大1.
			vector<int> leftNums(nums.begin(), nums.begin() + mid);   
			vector<int> rightNums(nums.begin() + mid + 1, nums.end());

			root->left = sortedArrayToBST(leftNums);
			root->right = sortedArrayToBST(rightNums);
			return root;
		}
	}
};

void levelTraverse(TreeNode* root){
	queue<TreeNode*> q;
	TreeNode* b;
	if (root){
		q.push(root);
		while (!q.empty()){
			b = q.front();
			cout << b->val << " ";
			q.pop();
			if (b->left){
				q.push(b->left);
			}
			if (b->right){
				q.push(b->right);
			}
		}
	}
}


int main(){
	Solution solution;
	TreeNode * root;
	vector<int> nums = { -10, -3, 0, 5, 9 };
	root = solution.sortedArrayToBST(nums);
	levelTraverse(root);
	return 0;
}