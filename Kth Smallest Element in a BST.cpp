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
	Solution(){
		index = 0;
	}
    int kthSmallest(TreeNode* root, int k) {
    	preOrder(root, k);
    	return ksmallest;
    }
    void preOrder(TreeNode* root, int k){
    	if(root == NULL){
    		return;
    	}
    	else{
    		preOrder(root->left, k);
    		index++;
    		if(index == k){
    			ksmallest = root->val;
    		}
    		preOrder(root->right, k);
    	}
    }

private:
	int index;
	int ksmallest;
};