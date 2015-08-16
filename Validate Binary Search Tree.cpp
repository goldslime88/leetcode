#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
    	if(root == NULL){
    		return true;
    	}
    	else{
    		bool flagl = false, flagr = false;
    		TreeNode* templ = root->left;
    		if(templ == NULL){
    			flagl = true;
    		}
    		else{
    			while(templ->right != NULL){
    				templ = templ->right;
    			}
    			if(templ->val < root->val){
    				flagl = true;
    			}
    			else{
    				flagl = false;
    			}


    		}
    		TreeNode* tempr = root->right;
    		if(tempr == NULL){
    			flagr = true;
    		}
    		else{
    			while(tempr->left != NULL){
    				tempr = tempr->left;
    			}
    			if(tempr->val > root->val){
    				flagr = true;
    			}
    			else{
    				flagr = false;
    			}


    		}

    		return flagl && flagr && isValidBST(root->right) && isValidBST(root->left);


    	}
        
    }
};