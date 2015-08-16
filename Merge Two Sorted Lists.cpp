#include <iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	ListNode *temp1, *temp2, *head, *cur;
    	temp1 = l1;
    	temp2 = l2;
    	head = NULL;
    	cur = NULL;
    	if(l1 == NULL && l2 == NULL){
    		return NULL;
    	}
    	if(l1 == NULL && l2 != NULL){
    		return l2;
    	}
    	if(l1 != NULL && l2 ==NULL){
    		return l1;
    	}
    	while(temp1 != NULL && temp2 != NULL){
    		if(temp1->val <= temp2->val){
    			if(head == NULL){
    				head = temp1;
    				cur = temp1;
    			}
    			else{
    				cur->next = temp1;
    				cur = temp1;

    			}

    			temp1 = temp1->next;

    		}
    		else{
    			if(head == NULL){
    				head = temp2;
    				cur = temp2;
    			}
    			else{
    				cur->next = temp2;
    				cur = temp2;

    			}

    			temp2 = temp2->next;

    		}
    	}

    	while(temp1 != NULL){
    		cur->next = temp1;
    		cur = temp1;
    		temp1 = temp1->next;

    	}
    	while(temp2 != NULL){
    		cur->next = temp2;
    		cur = temp2;
    		temp2 = temp2->next;    		
    	}

    	return head;

        
    }
};

int main(){
	Solution *a;
	a = new Solution();
}