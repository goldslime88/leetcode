#include <iostream>
#include <queue>
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
	Solution(){

	}
    vector< vector<int> > levelOrderBottom(TreeNode *root) {
    	vector< TreeNode* > tree;
    	vector< int > nodeDepth;
    	vector< int > empty;
    	vector< vector<int> > ans ,result;
    	TreeNode* node;
    	int i = 0;
    	int depth;
    	if(root == NULL){
    		return ans;
    	}

    	tree.push_back(root);
    	nodeDepth.push_back(0);

    	while(i < tree.size()){
    		node = tree[i];
    		depth = nodeDepth[i];
    		++i;	
    		if(node->left != NULL){
    			tree.push_back(node->left);
    			nodeDepth.push_back(depth+1);

    		}
    		if(node->right != NULL){
    			tree.push_back(node->right);
    			nodeDepth.push_back(depth+1);
    		}
    	}

    	// for(int i = 0; i < tree.size(); ++i){
    	// 	cout<<nodeDepth[i]<<endl;
    	// }


    	for(int i = 0; i < tree.size(); ++i){
    		
    		if(ans.size() <= nodeDepth[i]){
    			ans.push_back(empty);
    		}
    		ans[nodeDepth[i]].push_back(tree[i]->val);
    		
    	}
    	
    

    	return ans;





    }      
   
};

int main(){

	Solution* a;
	vector< vector<int> > ans;
	a = new Solution();
	TreeNode *tn1, *tn2, *tn3;
	tn1 = new TreeNode(1);
	tn2 = new TreeNode(2);
	tn3 = new TreeNode(3);
	tn1->left = tn2;
	tn1->right = tn3;
	ans = a->levelOrderBottom(tn1);
	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j){
			cout<< ans[i][j] <<endl;
		}
	
    }


}