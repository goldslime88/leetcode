#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//make trees that upper than now is flatten already. very cool
// it's like pre-order. now-left-right.put right to the lefts most right(left's last 
// in pre-order)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* now = root;
        while(now){
        	if(now->left){
        		TreeNode* n = now->left;
        		while(n->right){
        			n = n->right;
        		}
        		n->right = now->right;
        		now->right = NULL;
        		now->right = now->left;
        		now->left = NULL;
        		
        	}
        	else if(!now->left){

        	}
        	now = now->right;
        	
        }
    }
};