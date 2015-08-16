#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	return build(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());

    }

    TreeNode *build(vector<int>::iterator in1, vector<int>::iterator in2, vector<int>::iterator po1, vector<int>::iterator po2){
    	

    	if(in1 == in2 && po1 == po2){
    		return NULL;
    	}
    	else{
    		int valRoot = *(po2-1);
    		
    		

    		TreeNode *root = new TreeNode(valRoot);
    		vector<int>::iterator inm;
    		


    		for(vector<int>::iterator it = in1; it != in2; ++it){

       			if(*it == valRoot){
       				inm = it;

    			}
    		}
    		    		
    		// vector<int>::iterator it = postorder.begin()+inorder1.size();

    		// vector<int> postorder1(postorder.begin(), it);
    		// vector<int> postorder2(it, postorder.end()-1);
    		vector<int>::iterator pom = po1;
    		for(int i=0; i < inm-in1; ++i){
    			pom++;
    		}
    		    		

    		TreeNode* leftNode = build(in1, inm, po1, pom);
    		TreeNode* rightNode = build(inm+1, in2, pom, po2-1);
    		root->left = leftNode;
    		root->right = rightNode;

    		return root;

    	}
        
    }

};

int main(){
	Solution *a;
	a = new Solution();
	int in[] = {1,2};
	int po[] = {2,1};
	vector<int> inorder(in,in+sizeof(in)/sizeof(int));
	vector<int> postorder(po,po+sizeof(in)/sizeof(int));
	TreeNode* root = a->buildTree(inorder,postorder);
	cout<< root->val<<root->right->val<<endl;
}