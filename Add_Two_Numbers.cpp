#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        bool plus_one = false;
        while(temp1 && temp2){
        	
        	int value = temp1->val + temp2->val;
        	if(plus_one){
        		++value;
        	}

        	if(value >= 10){
        		value = value%10;
        		plus_one = true;
        	}
        	else{
        		plus_one = false;
        	}

        	ListNode* n = new ListNode(value);
        	if(head == NULL){
        		head = n;
        		tail = n;
        	}
        	else{
        		tail->next = n;
        		tail = n;
        	}

        	temp1 = temp1->next;
        	temp2 = temp2->next;
        }

        while(temp1){
        	int value = temp1->val;
        	if(plus_one){
        		++value;
        		
        	}

        	if(value >= 10){
        		value = value%10;
        		plus_one = true;
        	}
        	else{
        		plus_one = false;
        	}

        	ListNode* n = new ListNode(value);
        	if(head == NULL){
        		head = n;
        		tail = n;
        	}
        	else{
        		tail->next = n;
        		tail = n;
        	}

        	temp1 = temp1->next;
        }

        while(temp2){
        	int value = temp2->val;
        	if(plus_one){
        		++value;
        		
        	}
        	if(value >= 10){
        		value = value%10;
        		plus_one = true;
        	}
        	else{
        		plus_one = false;
        	}
        	ListNode* n = new ListNode(value);
        	if(head == NULL){
        		head = n;
        		tail = n;
        	}
        	else{
        		tail->next = n;
        		tail = n;
        	}

        	temp2 = temp2->next;
        }

        if(plus_one){
        	ListNode* n = new ListNode(1);
        	tail->next = n;
        }

        return head;

    }
};