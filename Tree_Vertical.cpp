#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution{

public:
	unordered_map< int , vector<TreeNode*> > record;
	unordered_map< int , vector<TreeNode*> >::iterator itRecord;
	void classifyNode(TreeNode* root, int myClass){
		if(root == NULL){
			return;
		}
		else{
			itRecord = record.find(myClass);
			if(itRecord == record.end()){
				vector<TreeNode*> temp;
				temp.push_back(root);
				record[myClass] = temp;
			}
			else{
				record[myClass].push_back(root);
			}

			classifyNode(root->left, myClass-1);
			classifyNode(root->right, myClass+1);
		}


	}

};





int main(int argc, char const *argv[])
{
	solution *aha;
	aha = new solution();
	TreeNode* root, *a, *b, *c;
	root = new TreeNode(0);
	a = new TreeNode(1);
	b = new TreeNode(2);
	c = new TreeNode(3);
	root->left = a;
	root->right = b;
	a->right = c;
	aha->classifyNode(root, 0);
	for(unordered_map< int , vector<TreeNode*> >::iterator it = (aha->record).begin(); it !=  (aha->record).end(); ++it){
		cout<<it->first<<endl;
		for(int i = 0 ; i < (it->second).size(); ++i){
			cout<<(it->second)[i]->val<<' ';
		}
		cout<<endl;
	}


	return 0;
}

