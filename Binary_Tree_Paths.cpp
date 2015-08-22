#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        traverseTree(root);
        return ans;
    }
    void traverseTree(TreeNode* node) {
    	if (node == NULL)
    	{
    		return;
    	}
    	else
    	{
    		record.push_back(node->val);
    		if(node->left != NULL && node->right != NULL)
    		{
    			traverseTree(node->left);
    			traverseTree(node->right);
    		}
    		else if(node->left != NULL && node->right == NULL)
    		{
    			traverseTree(node->left);
    		}
    		else if(node->left == NULL && node->right != NULL)
    		{
    			traverseTree(node->right);
    		}
    		else
    		{
    			string res;
    			for(int i = 0; i < record.size(); ++i)
    			{
    				if( i == 0 )
    				{
    					res = res + to_string(record[i]);
    				}
    				else
    				{
    					res = res + "->" + to_string(record[i]);
    				}
    			}
    			ans.push_back(res);
    			cout<<res<<endl;
    		}
    		record.pop_back();
    	}
    }

private:
	vector<int> record;
	vector<string> ans;
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();

	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	a->left = b;
	s->binaryTreePaths(a);

	return 0;
}