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
    bool isPalindrome(ListNode* head) 
    {
    	vector<int> val_store_in_array;
        ListNode *temp = head;
        while ( temp != NULL )
        {
        	val_store_in_array.push_back(temp->val);
        	temp = temp->next;
        }
        unsigned int size_of_array = val_store_in_array.size();
        for ( unsigned int i = 0; i < size_of_array/2; ++i )
        {
        	if ( val_store_in_array[i] != val_store_in_array[size_of_array - 1 - i] )
        	{
        		return false;
        	}
        }

        return true;
    }
};