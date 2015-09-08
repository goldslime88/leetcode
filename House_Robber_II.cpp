#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0){
        	return 0;
        }
        if(nums.size() == 1){
        	return nums[0];
        }
        if(nums.size() == 2){
        	return max(nums[0], nums[1]);
        }
        //pick first one
    	vector<int> ans1(nums.size()-1, 0);
    	int max1 = 0;
    	ans1[0] = nums[0];
    	ans1[1] = nums[0];

    	for(int i = 2; i < nums.size()-1; ++i){
    		ans1[i] = max(ans1[i-2]+nums[i], ans1[i-1]);
    	}
    	if(nums.size() == 3){
    		max1 = nums[0];
    	}
    	else{
    		max1 = ans1[nums.size()-2];
    	}

        //not pick first one
        vector<int> ans2(nums.size()-1, 0);
        int max2 = 0;
        ans2[0] = nums[1];
        ans2[1] = max(nums[1],nums[2]);
        for(int i = 2; i < nums.size()-1; ++i){
        	ans2[i] = max(ans2[i-2]+nums[i+1], ans2[i-1]);       	
        }
        max2 = ans2[nums.size()-2];
        return max(max1,max2);
    }
};