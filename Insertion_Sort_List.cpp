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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted_head = NULL;
        ListNode* sorted_tail = NULL;
        ListNode* now = head;
        if(now == NULL){
        	return NULL;
        }
        while(now){
        	ListNode* temp = now->next;
        	//very important!!!!!!!
        	now->next = NULL;
        	if(sorted_head == NULL){
        		sorted_head = now;
        		sorted_tail = now;
        		now = temp;
        		continue;
        	}
        	ListNode* sorted_temp = sorted_head;
        	ListNode* pre = NULL;
        	while(sorted_temp != NULL && now->val > sorted_temp->val){
        		pre = sorted_temp;
        		sorted_temp = sorted_temp->next;

        	}
        	if(sorted_temp == NULL){
        		sorted_tail->next = now;
        		sorted_tail = now;
        	}
        	else{
        		if(sorted_temp == sorted_head){
        			now->next = sorted_head;
        			sorted_head = now;
        		}
        		else{
        			pre->next = now;
        			now->next = sorted_temp;
        		}
        	}
        	now = temp;

        }


        return sorted_head;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	ListNode* a = new ListNode(3);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(4);
	a->next = b;
	b->next = c;
	ListNode* res =  s->insertionSortList(a);
	while(res){
		cout<< res->val<<" ";
		res = res->next;
	}

	return 0;
}