#include <iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* temp1, *temp2, *next, *pre;
        if(head == NULL){
        	return head;
        }
        next = head;
        while(next!=NULL && next->next != NULL){
        	
        	temp1 = next;
        	temp2 = next->next;
        	next = next->next->next;
        	if(temp1 == head){
        		temp1->next = temp2->next;
        		temp2->next = temp1;
        		head = temp2;
    
        	}
        	else{
        		temp1->next = temp2->next;
        		temp2->next = temp1;
        		pre->next = temp2;
        	}
        	
        	pre = temp1;
        	

        }
        return head;
    }
};