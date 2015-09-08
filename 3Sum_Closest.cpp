#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dif = INT_MAX;
        int res;
        for(int i = 0; i < nums.size()-2; ++i){
        	int j = i + 1;
        	int k = nums.size() - 1;
        	while(j < k){
        		int temp = nums[i] + nums[j] + nums[k];
        		if( temp < target ){
        			++j;
        		}
        		else if( temp > target ){
        			--k;
        		}
        		else{
        			return target;
        		}
        		if(abs(temp-target) < dif){
        			dif = abs(temp-target);
        			res = temp;
        		}
        	}
        }
        return res;
    }
};