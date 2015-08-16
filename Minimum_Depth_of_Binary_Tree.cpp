#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:

	Solution(){
		theMinDepth = 65560;
		depth = 0;
        isRoot = 1;
	}
    int minDepth(TreeNode *root) {
        if(isRoot == 1 && root == NULL){
                theMinDepth = 0;

        }
        isRoot = 0;

        if(root == NULL){
    		
    

    	}
    	else{

       			depth++;

                if(root->left == NULL && root->right ==NULL){
        			
                    if(theMinDepth > depth){
                        theMinDepth = depth;
                    }
        			
    			}

                minDepth(root->left);
                minDepth(root->right);
                depth--;

    	}

        return theMinDepth;
    }

        
private:   

	int theMinDepth;
	int depth;
    int isRoot;
};

int main(){
    Solution a;
    TreeNode t1(1),t2(2),t3(3),t4(4),t5(5);
    TreeNode* pt1=&t1, *pt2=&t2, *pt3=&t3, *pt4=&t4, *pt5=&t5;

    pt1->right=pt2;
    //pt1->right=pt3;
    // pt2->left=pt4;
    // pt3->right=pt5;
    std::cout<<a.minDepth(NULL)<<std::endl;

}