#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool smaller = true;
        if(nums.empty()){
        	return;
        }
        for(int i = 0; i < nums.size()-1; ++i){
        	if(smaller){
        		if(nums[i] > nums[i+1]){
        			int temp = nums[i];
        			nums[i] = nums[i+1];
        			nums[i+1] = temp;
        		}
        	}
        	else{
        		if(nums[i] < nums[i+1]){
        			int temp = nums[i];
        			nums[i] = nums[i+1];
        			nums[i+1] = temp;
        		}

        	}
        	smaller = !smaller;
        }
    }
};