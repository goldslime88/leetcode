#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     vector<TreeNode*> children;
     TreeNode(int x) : val(x){}
};


class solution{
public:

	vector<int> levelAns;
	vector<TreeNode*> ans;

	void BFS(TreeNode *root){
		
		queue<int> levelQueue;
		queue<TreeNode*> ansQueue;

		levelQueue.push(0);
		ansQueue.push(root);
		while(!ansQueue.empty()){
			TreeNode* temp = ansQueue.front();
			int tempLevel = levelQueue.front();
			ansQueue.pop();
			levelQueue.pop();
			levelAns.push_back(tempLevel);
			ans.push_back(temp);
			for(int i = 0; i < (temp->children).size(); ++i){
				ansQueue.push((temp->children)[i]);
				levelQueue.push(tempLevel+1);
			}
		}
		int pre = -1;
		for(int i = 0; i < ans.size(); ++i){
			if(levelAns[i] != pre){
				cout<<endl;
			}
			pre = levelAns[i];
			cout<<ans[i]->val<<" ";
		}

		cout<<endl;

	}

};

int main(int argc, char const *argv[])
{
	solution *aha;
	aha = new solution();
	TreeNode* a, *b,*c, *d;
	a= new TreeNode(0);
	b = new TreeNode(1);
	c = new TreeNode(2);
	d = new TreeNode(3);
	(a->children).push_back(b);
	(b->children).push_back(c);
	(b->children).push_back(d);
	aha->BFS(a);

	return 0;
}
