
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp;
        temp = head;
        set< ListNode* > record;
        if(temp == NULL){
        	return false;
        }
        while(temp -> next != NULL){
        	set< ListNode* >::iterator it = record.find(temp);
        	if(it == record.end()){
        		record.insert(temp);
        	}
        	else{
        		return true;
        	}
        	temp = temp->next;
        }

        return false;


    }
};