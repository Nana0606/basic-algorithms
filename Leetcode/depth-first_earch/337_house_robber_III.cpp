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
		if (it != map_val.end()){  //˵���Ѿ�map_val��
			cout << "��map��" << endl;
			return it->second;  // it->first��ȡTreeNode���ͣ�it->second��ȡint����
		}

		int val = 0;
		if (root->left != nullptr){
			val += rob(root->left->left) + rob(root->left->right);
		}
		if (root->right != nullptr){
			val += rob(root->right->left) + rob(root->right->right);
		}

		//�����������1����ǰroot�ڵ㱻͵����ǰ�ڵ㣬�ͺ��ӵĺ��ӿ���ͬʱ��͵
		//2����ǰroot����͵�����ӽڵ㱻͵
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
		cout << "������" << data << "����ڵ㣨-1��ʾ�գ�" << endl;
		root->left = createBinary();
		cout << "������" << data << "���ҽڵ㣨-1��ʾ�գ�" << endl;
		root->right = createBinary();
	}
	return root;
}

int main(){
	TreeNode *root;
	cout << "��������ڵ�" << endl;
	root = createBinary();
	Solution solution;
	int res = solution.rob(root);
	cout << res << endl; 
	return 0;
}