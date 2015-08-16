#include <stddef.h>
#include <iostream>

struct TreeNode {
    int val;
	TreeNode *left;
 	TreeNode *right;
  	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int max(int a, int b);

int depthOfTree(TreeNode *root);

bool isBalanced(TreeNode *root) {

	if(root == NULL){

	}
	else{
		if(isBalanced(root->left)==false)
		return false;
		if(isBalanced(root->right)==false)
		return false;
		if(depthOfTree(root->left)-depthOfTree(root->right) > 1 || 
			depthOfTree(root->left)-depthOfTree(root->right) < -1){
			return false;
		}


	}

	return true;


	
    
}

int depthOfTree(TreeNode *root){
	if(root == NULL){
		return 0;
	}
	else{
		return 1 + max(depthOfTree(root->left),depthOfTree(root->right));
	}
}

int max (int a, int b){
	if(a >= b)
	return a;
	else
	return b;    
}


int main(){
	TreeNode* T = new TreeNode(0);
	TreeNode* T1 = new TreeNode(0);
	TreeNode* T2 = new TreeNode(0);
	TreeNode* T3 = new TreeNode(0);
    TreeNode* T4 = new TreeNode(0);
    TreeNode* T5 = new TreeNode(0);
    TreeNode* T6 = new TreeNode(0);

    T->left=T1;
    T->right=T2;
    T1->left=T3;
    T2->right=T4;
    T3->left=T5;
    T4->right=T6;


	std::cout<< isBalanced(T)<<std::endl;

}