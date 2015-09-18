#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > ans;
        if(root == NULL){
        	return ans;
        }
        queue<TreeNode*> node_queue;
        queue<int> level_queue;
        node_queue.push(root);
        level_queue.push(1);
 
        bool order = true;
        vector<int> res;
        while(!node_queue.empty()){
        	TreeNode* n = node_queue.front();
        	res.push_back(n->val);
        	node_queue.pop();
        	int l = level_queue.front();
        	level_queue.pop();
        	if(n->left != NULL){
        		node_queue.push(n->left);
        		level_queue.push(l+1);
        	}
        	if(n->right != NULL){
        		node_queue.push(n->right);
        		level_queue.push(l+1);
        	}
        	if(l != level_queue.front() || node_queue.empty()){
        		if(order == false){
        			reverse(res.begin(), res.end());
        		}
        		ans.push_back(res);
        		res.clear();
        		order = !order;
        	}
        }

        return ans;

    }
};