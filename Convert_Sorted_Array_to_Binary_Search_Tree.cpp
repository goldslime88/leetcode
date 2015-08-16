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

private:
	TreeNode* root;
	vector<int> myNum;
public:
	Solution(){
		root = NULL;
	}
    TreeNode *sortedArrayToBST(vector<int> &num) {
    	if(num.empty()){
    		return root;
    	}
    	myNum = num;
    	int i = 0, j = myNum.size()-1;
    	orderInsert(i , j);

    	return root;
        
    }

    void orderInsert(int begin, int end){
    	if(begin == end){
    		TreeNode* n = new TreeNode(myNum[begin]);
    		insert(n);
    		return;
    	}
    	else{

    		int mid = (begin + end)/2;
    		TreeNode* n = new TreeNode(myNum[mid]);
    		insert(n);
    		if(begin <= mid-1){
    				orderInsert(begin, mid-1);

    		}
    		if(end >= mid+1){
    	    		orderInsert(mid+1, end);
    	    }
    	}



    }
    void insert(TreeNode* n){
    	if(root == NULL){
    		root = n;
    		return;
    	}
    	else{
    		TreeNode* temp = root;
    		while(temp != NULL){
    			if(temp->val >= n->val){
    				if(temp->left == NULL){
    					temp->left = n;
    					break;
    				}
    				temp = temp->left;
    			}
    			else{
    				if(temp->right == NULL){
    					temp->right = n;
    					break;
    				}
    				temp = temp->right;

    			}
    		}
    		return;
    	}
    }
};