#include <iostream>
#include <queue>
#include <stack>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	Solution(){}
    bool isSymmetric(TreeNode *root) {
        if(root == NULL){
            return true;
        }

        return aSymmetric(root->left, root->right);
        
    }

    bool aSymmetric(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL){
            return true;
        }
        else if((left == NULL && right != NULL)||(left != NULL && right == NULL)){
            return false;

        }
        else{
            if(left->val != right->val){
                return false;
            }
            else{
                return (aSymmetric(left->left, right->right)&&aSymmetric(left->right, right->left));
            }
        }
    }
 



    bool notRecursiveIsSymmetric(TreeNode *root) {
    	queue< TreeNode* > treeQueue;
    	stack< int > valstack;
    	if(root == NULL){
    		return true;
    	}

    	TreeNode* nullNode;
    	nullNode = new TreeNode(-1);

    	treeQueue.push(root);
    	while(!treeQueue.empty()){
    		TreeNode* temp =  treeQueue.front();
    		treeQueue.pop();
    		if(temp != root){
    			if(valstack.empty()){
    			valstack.push(temp->val);
    			cout<<"push: "<<temp->val<<endl;
    			}
    			else{
    				if(valstack.top() == temp->val){
    					cout<<"pop: "<<valstack.top()<<endl;
    					valstack.pop();
    				}
    				else{
    					valstack.push(temp->val);
    					cout<<"push: "<<temp->val<<endl;
    				}
    			}

    		}

    		if(temp != nullNode){

    			if(temp->left != NULL){
    				treeQueue.push(temp->left);
    			}
    			else{
    				treeQueue.push(nullNode);
    			}

    			if(temp->right != NULL){
    				treeQueue.push(temp->right);
    			}
    			else{
    				treeQueue.push(nullNode);
    			}
    		}
    	}

    	if(valstack.empty()){
    		return true;
    	}
    	else{
    		return false;
    	}
    }


};

int main(){
	Solution* a;
	a = new Solution();
	TreeNode *t1, *t2, *t3, *t4, *t5;
	t1 = new TreeNode(1);
	t2 = new TreeNode(2);
	t3 = new TreeNode(2);
	t4 = new TreeNode(3);
	t5 = new TreeNode(3);

	t1->left = t2;
	t1->right = t3;
	t2->right = t4;
	t3->right = t5;

	cout<< a->isSymmetric(t1)<<endl;



}