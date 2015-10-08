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
	Solution() {
		wrong_1 = NULL;
		wrong_2 = NULL;
		pre = NULL;
	}
    void recoverTree(TreeNode* root) {
    	inorderTree(root);
    	int temp = wrong_1->val;
    	wrong_1->val = wrong_2->val;
    	wrong_2->val = temp;
    	return;
        
    }
    void inorderTree(TreeNode* n) {
    	if(n == NULL){
    		return;
    	}
    	else{
    		inorderTree(n->left);
    		if(pre != NULL && wrong_1 == NULL && n->val < pre->val){
    			wrong_1 = pre;
    			
    		}
    		//case 0 left 1 right null. do not use else if.
    		if( pre != NULL && wrong_1 != NULL && n->val < pre->val ){
    			wrong_2 = n;
    			
    		}
    		pre = n;
    		

    		inorderTree(n->right);		
    	}
    }


private:
	TreeNode* wrong_1;
	TreeNode* wrong_2;
	TreeNode* pre;
};