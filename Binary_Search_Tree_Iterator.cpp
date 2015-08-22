#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        gen_record(root);
        order_num = 0;

    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(record.size()==0 || order_num > record.size()-1){
        	return false;
        }
        return true;
    }

    /** @return the next smallest number */
    int next() {

        return ( record[ order_num++ ] );
    }
private:
	vector<int> record;
	int order_num;
	void gen_record(TreeNode *node){
		if(node == NULL){
			return;
		}
		else{
			gen_record(node->left);
			record.push_back(node->val);
			gen_record(node->right);
		}
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(1);
	BSTIterator i = BSTIterator(root);
 		
 	while (i.hasNext()) cout << i.next()<<endl;
	return 0;
}
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */