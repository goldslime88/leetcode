#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		TreeNode *temp = root;
		while ( temp != NULL )
		{
			if ( p->val > temp->val && q->val > temp->val )
			{
				temp = temp->right;
			}
			else if ( p->val < temp->val && q->val < temp->val )
			{
				temp = temp->left;
			}
			else
			{
				return temp;
			}
			
		}
		return temp;
			
	}
};

