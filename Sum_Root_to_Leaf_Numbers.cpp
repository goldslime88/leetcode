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
    int sumNumbers(TreeNode* root) {
        sum = 0;
        if(root == NULL){
        	return 0;
        }
        recurNumbers(root, 0);
        return sum;
    }
    void recurNumbers(TreeNode* n, int num){
    	if(n == NULL){
    		return;
    	}
    	else{
    		num = num * 10 + n->val;
    		if(n->left == NULL && n->right == NULL){
    			sum = sum + num;
    		}
    		recurNumbers(n->left, num);
    		recurNumbers(n->right, num);
    	}
    }

private:
	int sum;
};