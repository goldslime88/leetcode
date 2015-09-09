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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recurBuild(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* recurBuild(vector<int>& preorder, vector<int>& inorder, int pre_head, int pre_tail,
    	int in_head, int in_tail){
    	if(pre_head>pre_tail || in_head>in_tail){
    		return NULL;
    	}
    	//this is not necessary.
    	// if(pre_head == pre_tail && in_head == in_tail){
    	// 	TreeNode* n = new TreeNode(preorder[pre_head]);
    	// 	return n;
    	// }

    	TreeNode* n = new TreeNode(preorder[pre_head]);
    	int index_mid;
    	for(int i = in_head; i <= in_tail; ++i){
    		if(preorder[pre_head] == inorder[i]){
    			index_mid = i;
    			break;
    		}
    	}
    	int left_num = index_mid - in_head;
    	int right_num = in_tail - index_mid;
    	TreeNode* left_n = recurBuild(preorder, inorder, pre_head+1, pre_head+left_num, 
    		in_head, index_mid-1);
    	TreeNode* right_n = recurBuild(preorder, inorder, pre_head+left_num+1, pre_tail, 
    		index_mid+1, in_tail);
    	n->left = left_n;
    	n->right = right_n;
    	return n;

    }
};