#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record;
        for(int i = 0; i < nums.size(); ++i){
        	if(record.find(nums[i]) == record.end()){
        		record.insert(nums[i]);
        	}
        	else{
        		return true;
        	}
        }
        return false;
    }
};