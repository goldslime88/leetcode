#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if( head == NULL ){
    		return NULL;
    	}
        if( k == 1){
        	return head;
        }
        ListNode* count_temp = head;
        int count_all = 0;
        while(count_temp){
        	count_temp = count_temp->next;
        	count_all ++;
        }
        if(count_all < k){
        	return head;
        }

        int count = k;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre_head = dummy;
       	ListNode* reverse_temp = pre_head->next;
 
       	while(1){

 			while(--count){
 				ListNode* temp = reverse_temp->next;
				reverse_temp->next = temp->next;
				temp->next = pre_head->next;
				pre_head->next = temp;
 							
       		}
       		count_all = count_all - k;
       		if(count_all < k){
       			break;
       		}
       		else{
       			count = k;
       			pre_head = reverse_temp;
       			reverse_temp = pre_head->next;      		
       		}
       	}
       	return dummy->next;

    }
};

int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	s->reverseKGroup(a, 3);
	return 0;
}