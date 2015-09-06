#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	int count(ListNode* head){
		ListNode* temp = head;
		int sum = 0;
		while(temp){
			temp = temp->next;
			sum ++;
		}

		return sum;
	}

    TreeNode* sortedListToBST(ListNode* head) {
        int total_num = count(head);

        return recurSortList(head, total_num);

    }
    TreeNode* recurSortList(ListNode* head, int len){
    	if(len == 0){
    		return NULL;
    	}
    	if(len == 1){
    		TreeNode* n = new TreeNode(head->val);
    		return n;
    	}

    	int mid;
        if(len%2 != 0){
        	mid = len/2 + 1;
        }
        else{
        	mid =len/2;
        }
        int count = mid;
        ListNode* temp = head;
        while(count > 1){
        	temp = temp->next;
        	--count;
        }
        ListNode* mid_list_node = temp;
        ListNode* right_head = temp->next;
        int len_left = mid - 1;
        int len_right = len - mid;
        TreeNode* mid_node = new TreeNode(mid_list_node->val);
        mid_node->left = recurSortList(head, len_left);
        mid_node->right = recurSortList(right_head, len_right);
        return mid_node;
    }

};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(5);
	ListNode* n3 = new ListNode(8);
	n1->next = n2;
	n2->next = n3;
	s->sortedListToBST(n1);

	return 0;
}





