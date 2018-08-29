# include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

bool isSameTree(TreeNode* p, TreeNode* q){
	if (p == NULL || q == NULL){    //�ж� �����һ��ΪNULL����Ϊ����
		if (p == NULL && q == NULL) return true;
		else return p == q;
	}
	return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
	// �������������
	return 0;
}