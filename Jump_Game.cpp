#include <iostream>
#include <vector>
using namespace std;

//cool method called max reach
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int i;
    	int reach = 0;
        for(i = 0; i < nums.size() && i <= reach; ++i){
        	reach = max(i + nums[i],reach);
        }
        if(i == nums.size()){
        	return true;
        }
        else{
        	return false;
        }
    }
};