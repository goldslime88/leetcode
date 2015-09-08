#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	if(head == NULL){
    		return NULL;
    	}
        ListNode* now = head;
        ListNode* small_head = NULL;
        ListNode* small_tail = NULL;
        ListNode* big_head = NULL;
        ListNode* big_tail = NULL;
        while(now){
        	ListNode* temp = now->next;
        	if(now->val < x){
        		if(!small_head){
        			small_head = now;
        			small_tail = now;
        		}
        		else{
        			small_tail->next = now;
        			small_tail = now;
        		}
        	}
        	if(now->val >= x){
        		if(!big_head){
        			big_head = now;
        			big_tail = now;
        		}
        		else{
        			big_tail->next = now;
        			big_tail = now;
        		}
        	}
        	now = temp;

        }
        if(small_tail){
        	small_tail->next = big_head;
        }
        if(big_tail){
        	big_tail->next = NULL;
        }
        if(!small_head){
        	return big_head;
        }
        return small_head;
    }
};