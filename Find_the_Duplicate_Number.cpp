#include <vector>
#include <iostream>
using namespace std;

//1 - n and set a mid, loop array and count all ele smaller eq than mid 
//if count > mid, in the left, else in the right
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int begin = 1;
        int end = nums.size()-1;

        while(begin < end){
        	int mid = (begin+end)/2;
        	int count = 0;
        	for(int i =0; i < nums.size(); ++i){
        		if(nums[i]<=mid){
        			++count;
        		}
        	}
        	if(count > mid){
        		end = mid;
        	}
        	else{
        		begin = mid + 1;
        	}
        }

        return end;
    }
};