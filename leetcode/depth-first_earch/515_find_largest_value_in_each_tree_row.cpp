# include<iostream>
# include<vector>
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
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		int level = 0;
		traverse(root, res, level);
		return res;
	}

	void traverse(TreeNode* root, vector<int> &res, int level){
		if (root == nullptr) return;
		if (res.size() == level){
			res.push_back(root->val);
		}
		else{
			res[level] = max(res[level], root->val);
		}
		traverse(root->left, res, level + 1);
		traverse(root->right, res, level + 1);
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
	vector<int> res = solution.largestValues(root);
	for (int i = 0; i < int(res.size()); i++){
		cout << res[i] << endl;
	}
	return 0;
}