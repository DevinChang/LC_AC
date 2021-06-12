/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
	TreeNode* R;
	vector<TreeNode*> h;

    CBTInserter(TreeNode* root) {
		h.resize(1);
		R = root;
		queue<TreeNode*> q;
		q.push(root);
		while(q.size()) {
			auto t = q.front();
			q.pop();
			h.push_back(t);
			if(t->left) q.push(t->left);
			if(t->right) q.push(t->right);
		}
    }
    
    int insert(int v) {
		auto t = new TreeNode(v);
		h.push_back(t);
		int k = h.size() - 1;
		int p = k / 2;
		if(p * 2 == k) h[p]->left = t;
		else h[p]->right = t;
		return h[p]->val;
    }
    
    TreeNode* get_root() {
		return R;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */