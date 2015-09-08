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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    	vector<TreeNode*> record;
        recurFind(root, record, p, q);
        int i;
        for(i = 0; i < min(p_ancestors.size(), q_ancestors.size()); ++i){
        	if(p_ancestors[i] == q_ancestors[i]){
        		continue;
        	}
        	else{
        		break;
        	}
        }
        if(i == min(p_ancestors.size(), q_ancestors.size())){
        	if(p_ancestors.size() <= q_ancestors.size()){
        		return p_ancestors[p_ancestors.size()-1];
        	}
        	else{
        		return q_ancestors[q_ancestors.size()-1];
        	}
        }
        else{
        	return q_ancestors[i-1];
        }
    }
    void recurFind(TreeNode* n, vector<TreeNode*>& record, TreeNode* p, TreeNode* q){
    	if( n == NULL){
    		return;
    	}
    	else{
    		record.push_back(n);
    		if(n==p){
    			for(int i = 0; i < record.size(); ++i){
    				p_ancestors.push_back(record[i]);

    			}
    		}
    		if(n==q){
    			for(int i = 0; i < record.size(); ++i){
    				q_ancestors.push_back(record[i]);
    			}
    		}
    		recurFind(n->left, record, p, q);
    		recurFind(n->right, record, p, q);
    		record.pop_back();
    	}
    }

private:
	vector<TreeNode*> p_ancestors;
	vector<TreeNode*> q_ancestors;
};	