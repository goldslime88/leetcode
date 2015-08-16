#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if( head == NULL)
    	{
    		return NULL;
    	}
    	if( head->next == NULL)
    	{
    		return head;
    	}
        if( head->next->next == NULL )
        {
        	ListNode* begin = head;
        	ListNode* mid = head->next;
        	head->next = NULL;
        	mid->next = head;
           	return mid;
        }
        ListNode* begin = head;
        ListNode* mid = head->next;
        ListNode* end = head->next->next;
        while ( end != NULL )
        {
        	if( begin == head ){
        		begin->next = NULL;
        	}
        	mid->next = begin;
        	begin = mid;
        	mid = end;
        	end = end->next;
        }
        mid->next = begin;
        return mid;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	a->next = b;
	b->next = c;
	s->reverseList(a);
	return 0;
}