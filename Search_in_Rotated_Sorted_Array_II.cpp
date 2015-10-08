#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size()-1;
        while(head <= tail){
        	int mid = (head+tail)/2;
        	if(nums[mid] == target){
        		return true;
        	}
        	//decide which side is sorted then decide which side to pick
        	if(nums[mid] > nums[head]){
        		//left is sorted
        		if(target >= nums[head] && target < nums[mid]){
        			//target in sorted part
        			tail = mid - 1;
        		}

        		else{
        			//target not in sorted part
        			head = mid + 1;
        		}
        	}
        	else if(nums[mid] < nums[head]){
        		if(target > nums[mid] && target <= nums[tail]){
        			head = mid + 1;
        		}
        		else{
        			tail = mid - 1;
        		}
        	}
        	else{
        		//if equal which cannot tell
        		head++;
        		//tricky move the head to find the first not equal
        	} 

        }

        return false;
    }
};