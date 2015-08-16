#include <stddef.h>
#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int addup;
    bool exist;
    Solution() {
        addup = 0;
        exist = false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
    if(root == NULL){

	}

	else{
		addup += root->val;
		if(root->left == NULL && root->right == NULL){
			if(sum == addup){
				exist = true;
			}
		}
		hasPathSum(root->left, sum);
		hasPathSum(root->right, sum);
		addup -= root->val;
	}

	return exist;

    }
};

int main(){
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);

	// t1->left = t2;
	// t1->right = t6;
	t2->left = t3;
	t2->right = t4;
	t4->left = t5;
	Solution *s = new Solution();
	std::cout<< s->hasPathSum(t1, 0) <<std::endl;


}
