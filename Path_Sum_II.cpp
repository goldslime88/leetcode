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
    vector< vector<int> > pathSum(TreeNode* root, int sum) {
        int sum_now = 0;
        vector<int> nums_now;
        recurSum(root, sum, sum_now, nums_now);
        return ans;
    }

    void recurSum(TreeNode* n, int sum, int sum_now, vector<int>& nums_now){
    	if(n == NULL){
    		return;
    	}
    	else{
    		sum_now = sum_now + n->val;
    		nums_now.push_back(n->val);
    		if(sum_now == sum && n->left == NULL && n->right == NULL){
    			ans.push_back(nums_now);
    		}
    		recurSum(n->left, sum, sum_now, nums_now);
    		recurSum(n->right, sum, sum_now, nums_now);
    		sum_now = sum_now - n->val;
    		nums_now.pop_back();

    	}

    }

private:
	vector< vector<int> > ans;
};