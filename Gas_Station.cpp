#include <iostream>
#include <vector>
using namespace std;
//can tail ++, cannot head --
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	if(gas.size() == 1){
    		if(gas[0] >= cost[0]){
    			return 0;
    		}
    		else{
    			return -1;
    		}
    	}
        int head = 0, tail = 1;
        int length = gas.size();
        int dif = gas[0] - cost[0];
        while(head != tail){
        	if(dif >= 0){
        		dif = dif + gas[tail] - cost[tail];
        		tail++;
        		if(tail == gas.size()){
        			tail = 0;
        		}

        	}
        	else{
        		head--;
        		if(head == -1){
        			head = gas.size()-1;
        		}
        		dif = dif + gas[head] - cost[head];
        	}

        }
        if(dif >= 0){
        	return head;
        }
		else{
			return -1;
		}    
	}
};