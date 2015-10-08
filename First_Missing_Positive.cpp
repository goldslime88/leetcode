#include <vector>
#include <iostream>
#include <set>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
        	while(nums[i]>0 && nums[i] <= size && nums[i] != nums[nums[i]-1]){
        		swap(nums[i], nums[nums[i]-1]);
        	}
        }

        
        for(int j = 0; j < size; ++j){
        	if(nums[j] != j+1){
        		return j+1;
        	}
        }
        return size + 1;

    }
};