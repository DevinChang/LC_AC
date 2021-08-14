#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
	char val;
	TreeNode *left, *right;
	TreeNode(char _val) : val(_val), left(nullptr), right(nullptr) {}
};

string res;

void dfs(TreeNode *root) {
	if(!root) return;
	res += root->val;
	dfs(root->left);
	dfs(root->right);
}


int main() {
	string inorder, lorder;
	cin >> inorder >> lorder;
	
	unordered_map<char,int> pos;
	for(int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;

	bool st[30] = {0};
	TreeNode *q[30];

	q[0] = new TreeNode(lorder[0]);
	// 按层遍历，i是当前这层的起点，j是下一层的起点
	for(int i = 0, j = 1; j < lorder.size();) {
		// 遍历当前层
		for(int end = j; i < end; i++) {
			int p = pos[lorder[i]];
			st[p] = true;
			// 判断左儿子是否存在
			if(p && !st[p-1]) {
				q[i]->left = new TreeNode(lorder[j]);
				q[j++] = q[i]->left;
			}
			// 判断右儿子是否存在
			if(p+1 < lorder.size() && !st[p+1]) {
				q[i]->right = new TreeNode(lorder[j]);
				q[j++] = q[i]->right;
			}
		}
	}
	dfs(q[0]);

	cout << res << endl;

	return 0;
}