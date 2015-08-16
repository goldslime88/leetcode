#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	Solution(){}
    ListNode *deleteDuplicates(ListNode *head) {
    	if(head == NULL){
    		return head;
    	}
        ListNode *parent = head;
    	ListNode *current = head->next;
    	while(current != NULL){
    		if(parent->val == current->val){
    			parent->next = current->next;
    			delete current;
    			current = parent->next;
    		}
    		else{
    			parent = current;
    			current = parent->next;
    		}

    	}

    	return head;

        
    }
};

int main(){

}