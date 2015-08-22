#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> ans( nums.size(), 0 );
        if(nums.size() == 0){
        	return 0;
        }
        if(nums.size() == 1){
        	return nums[0];
        }
        if(nums.size() == 2){
        	return nums[0]>nums[1]?nums[0]:nums[1];
        }
        ans[0] = nums[0];
        ans[1] = nums[0]>nums[1]?nums[0]:nums[1];
        for ( int i = 2; i < nums.size(); ++i )
        {
        	ans[i] = (ans[i-2]+nums[i]) > ans[i-1]?(ans[i-2]+nums[i]):ans[i-1];
        }
        return ans[nums.size()-1];
    }
};