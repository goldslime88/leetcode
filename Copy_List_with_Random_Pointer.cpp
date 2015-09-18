#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
//problem is random pointer point to the node not in the origin list
// we need to make it point to what we like(random)
//A->A'->B->B'->C->C'
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	  if(head == NULL){
    	  	return NULL;
    	  }
		  RandomListNode *temp = head;
		  while(temp){
		  	RandomListNode* copy_temp = new RandomListNode(temp->label);
		  	copy_temp->next = temp->next;
		  	temp->next = copy_temp;
		  	temp = copy_temp->next;
		  }
		  temp = head;
		  while(temp){
		  	RandomListNode* copy_temp = temp->next;
		  	if(temp->random){
		  		copy_temp->random = temp->random->next;		  		
		  	}
		  	else{
		  		copy_temp->random = NULL;
		  	}
		  	temp = copy_temp->next;

		  }
		  temp = head;
		  RandomListNode* copy = head->next;
		  RandomListNode* copy_head = head->next;
		  while(temp){
		  	temp->next = temp->next->next;
		  	temp = temp->next;
		  	if(!temp){
		  		copy->next = NULL;
		  	}
		  	else{
				copy->next = copy->next->next;		  		
		  	}
		  	copy = copy->next;

		  }
		  return copy_head;       
    }
};