#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size()-1;
        while(head <= tail){
        	int mid = (head+tail)/2;
        	if(nums[mid] == target){
        		return mid;
        	}
        	if(nums[mid] >= nums[head]){
        		if(target >= nums[head] && target < nums[mid]){
        			tail = mid - 1;
        		}
        		else{
        			head = mid + 1;
        		}
        	}
        	else{
        		if(target > nums[mid] && target <= nums[tail]){
        			head = mid + 1;
        		}
        		else{
        			tail = mid - 1;
        		}
        	} 

        }

        return -1;
    }
};