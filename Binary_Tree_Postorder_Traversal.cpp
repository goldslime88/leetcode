#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        post_traversal(root);
        return record;
    }
    void post_traversal(TreeNode *node){
    	if (node == NULL){
    		return;
    	}
    	else{
    		post_traversal(node->left);
    		post_traversal(node->right);
    		record.push_back(node->val);
    	}
    }
private:
	vector<int> record;
};