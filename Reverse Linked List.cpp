#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head) {
        ListNode* t1, *t2, *t3;
        if(head == NULL){
        	return NULL;
        }
        if(head->next == NULL){
        	return head;
        }
        if(head->next->next == NULL){
        	t1 = head->next;
        	head->next = NULL;
        	t1->next = head;
        	head = t1;
        	return head;
        }
        t1 = head;
        t2 = head->next;
        t3 = head->next->next;
        while(t3 != NULL){
        	if(t1 == head){
        		t1->next = NULL;
        	}
        	t2->next = t1;
        	t1 = t2;
        	t2 = t3;
        	t3 = t3->next; 
        }
        t2->next = t1;
        head = t2;
        return head;

    }
};


int main(int argc, char const *argv[])
{
	Solution* aha;
	aha = new Solution();
	ListNode *a,*b,*c,*d,*head;
	a = new ListNode(1);
	b = new ListNode(2);
	// c = new ListNode(5);
	// d = new ListNode(4);
	a->next = b;
	// b->next = c;
	// c->next = d;
	head=aha->reverseBetween(a);
	while(head!=NULL){
		cout<< head->val<<endl;
		head = head->next;
	}

	return 0;
}