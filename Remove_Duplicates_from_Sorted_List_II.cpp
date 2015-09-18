#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//learn recursive linked_List. It's much easy 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	//every time we see myself and my next
    	if(head == NULL){
    		return NULL;
    	}
    	if(head->next == NULL){
    		return head;
    	}

    	int head_val = head->val;
    	ListNode* next_node = head->next;
    	if(next_node->val != head_val){
    		head->next = deleteDuplicates(next_node);
    		return head;
    	}
    	else{
    		while( next_node && next_node->val == head_val ){
    			next_node = next_node->next;
    		}
    		return deleteDuplicates(next_node);
    	}

    }
};