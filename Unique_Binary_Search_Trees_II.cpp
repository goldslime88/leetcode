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
    vector<TreeNode*> generateTrees(int n) {
        return recurGenerate(1, n);
    }
    vector<TreeNode*> recurGenerate(int begin, int end){
    	vector<TreeNode*> ans;
    	if(begin > end){
    		ans.push_back(NULL);
    		return ans;
    	}
    	if(begin == end){
    		TreeNode * new_node = new TreeNode(begin);
    		ans.push_back(new_node);
    		return ans;
    	}
    	for(int i = begin; i <= end; ++i){
    		vector<TreeNode*> left =  recurGenerate(begin, i-1);
    		vector<TreeNode*> right = recurGenerate(i+1, end);
    		for(int left_tree = 0; left_tree < left.size(); ++left_tree){
    			for(int right_tree = 0; right_tree < right.size(); ++right_tree){
    				TreeNode * new_node = new TreeNode(i);
    				new_node->left = left[left_tree];
    				new_node->right = right[right_tree];
    				ans.push_back(new_node);
    			}
    		}
    	}

    	return ans;
    }


};	