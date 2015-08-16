#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); ++it){
        	if(record.find(*it) == record.end()){
        		record[*it] = it - nums.begin(); 
        	}
        	else{
        		if( it - nums.begin() -  record[*it] <= k){
        			return true;
        		}
        		else{
        			record[*it] = it - nums.begin();
        		}
        		
        	}
        }
        return false;
    }
};