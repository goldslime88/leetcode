#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	Solution(){}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a, *b;
        a = headA;
        b = headB;

        if(a == NULL || b == NULL){
        	return NULL;
        }

        while(a != NULL && b != NULL){
        	a = a->next;
        	b = b->next;
        }

        while(a != NULL){
        	a = a->next;
        	headA = headA->next;
        }

        while(b != NULL){
        	b = b->next;
        	headB = headB->next;
        }

        a = headA;
        b = headB;

        while(a != b){
        	a = a->next;
        	b = b->next;
        }

        return a;

    }

    ListNode *reverse(ListNode *head){
    	ListNode *p, *q, *s;
    	p = q = head;
    	while(q != NULL){
    		if(p == head){

    			q = p->next;
    			s = q->next;
    			p->next = NULL;
    			q->next = p;
    			p = q;
    			q = s;
    		}
    		else{

    			s = q->next;
    			q->next = p;
    			p = q;
    			q = s;
    		}

    	}
    	return p;
    }
};

int main(){
	ListNode *n1, *n2, *n3, *n4, *n5, *result;
	ListNode node1(1), node2(2), node3(3), node4(4), node5(5);
	n1 = &node1;
	n2 = &node2;
	n3 = &node3;
	n4 = &node4;
	n5 = &node5;
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n5->val = 5;
    n1->next = n2;
    n2->next = n4;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
	Solution a;
    result = a.getIntersectionNode(n1,n3);
	cout<< result->val <<endl;

     

}