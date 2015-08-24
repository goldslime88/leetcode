#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //level means the level below current node
        TreeLinkNode *cur = root;
        TreeLinkNode *head_of_level = NULL;
        TreeLinkNode *tail_of_level = NULL;

        //loop for different levels
        while(cur != NULL){
        	//loop for node in this level
        	while(cur != NULL){
        		if(cur->left != NULL){
        			if(head_of_level == NULL){
        				head_of_level = cur->left;
        				tail_of_level = cur->left;
        			}
        			else{
        				tail_of_level->next = cur->left;
        				tail_of_level = cur->left;
        			}
        		}
        		if(cur->right != NULL){
        			if(head_of_level == NULL){
        				head_of_level = cur->right;
        				tail_of_level = cur->right;
        			}
        			else{
        				tail_of_level->next = cur->right;
        				tail_of_level = cur->right;
        			}
        		}
        		cur = cur->next;
        	}

        	cur = head_of_level;
        	head_of_level = NULL;
        	tail_of_level = NULL;

        }
    }
};