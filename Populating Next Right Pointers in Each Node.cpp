#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
		queue<TreeLinkNode*> queueNode,prequeue;
		if(root != NULL){
			prequeue.push(root);
		}  	
		int index = 1;
		int record = 1;

		while(!prequeue.empty()){
			TreeLinkNode* temp;
			temp = prequeue.front();
			queueNode.push(temp);
			prequeue.pop();
			if(temp->left != NULL){
				prequeue.push(temp->left);
				
			}
			if(temp->right != NULL){
				prequeue.push(temp->right);

			}

		}
		cout<<queueNode.size()<<endl;
		while(!queueNode.empty()){
			TreeLinkNode* temp;
			temp = queueNode.front();
			queueNode.pop();
			if(index+1 == pow(2,record)){
				record++;
				temp->next = NULL;
			}
			else{
				temp->next = queueNode.front();
			}

			index++;

		}



    }
};

int main(int argc, char const *argv[])
{
	Solution* a;
	a = new Solution();
	TreeLinkNode* a1, *a2, *a3;
	a1 = new TreeLinkNode(1);
	a2 = new TreeLinkNode(2);
	a3 = new TreeLinkNode(3);
	a1->left = a2;
	a1->right = a3;
	a->connect(a1);
	cout<<"haha"<<endl;
	cout<<a2->next->val<<endl;


	return 0;
}