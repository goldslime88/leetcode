#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if( head == NULL )
        {
        	return NULL;
        }
        while(head->val == val)
        {
        	ListNode* temp = head;
        	head = head->next;
        	delete temp;
        	if( head == NULL )
        	{
        		return NULL;
        	}
        }
        ListNode* not_value = head;
        ListNode* new_head = head;
        while(not_value->next != NULL)
        {
        	if(not_value->next->val == val)
        	{
        		ListNode* temp = not_value->next;
        		not_value->next = not_value->next->next;
        		delete temp;
        	}
        	else
        	{
        		not_value = not_value->next;
        	}
        }

        return new_head;

    }
};