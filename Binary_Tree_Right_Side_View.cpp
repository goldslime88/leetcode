#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> bfs_queue;
        queue<int> level_queue;
        vector<int> ans;
        if(root == NULL){
        	return ans;
        }
        bfs_queue.push(root);
       	level_queue.push(0);
        while(!bfs_queue.empty()){
        	TreeNode* n = bfs_queue.front();
        	bfs_queue.pop();
        	int level = level_queue.front();
        	level_queue.pop();
        	if( n->left ){
        		bfs_queue.push(n->left);
        		level_queue.push(level+1);
        	}
        	if( n->right ){
        		bfs_queue.push(n->right);     		      
        		level_queue.push(level+1);
        	}
        	if(level < level_queue.front() || level_queue.empty()){
        		ans.push_back(n->val);
        	}
        }

        return ans;
    }
};