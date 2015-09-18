#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 //put selected node into between record_head and record_head->next;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n){
        	return head;
        }
        int count_m = m;
        int count_num = n - m;
        ListNode *pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode* record_head = pre_head;
        //m-1 times
        while(--count_m){
        	record_head = record_head->next;
        }
        ListNode* reverse_temp = record_head->next;
        //record_head -> reverse_temp -> reverse_temp_next
        //n-m times
        while(count_num--){
        	ListNode* reverse_temp_next = reverse_temp->next;
        	reverse_temp->next = reverse_temp_next->next;
        	reverse_temp_next->next = record_head->next;
        	record_head->next = reverse_temp_next;
        	

        }
        return pre_head->next;

    }
};