#include <cstddef>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	ListNode *p = head, *pp = head, *ppp = head;

    	for(int i = 0; i < n; ++i){
    		p = p->next;
    	}
    	if(p == NULL){
    		if(n == 1){
    			return NULL;
    		}
    		else{
    			head = head->next;
    			delete pp;
    			return head;
    		}
    	}
    	p = p->next;
    	while(p != NULL){
    		p = p->next;
    		pp = pp->next;
    	}
    	ListNode *temp = pp->next;
    	pp->next = (pp->next)->next;
    	delete temp;

    	return head;
        
    }
};

int main(){

}