
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
    	preorder(root);
    	return ans;
    }

    void preorder(TreeNode *root){
    	if(root == NULL){
    		return;
    	}
    	else{
    		ans.push_back(root->val);
    		preorder(root->left);
    		preorder(root->right);
    	}

    }
private:
	vector<int> ans;

};