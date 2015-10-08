#include <iostream>
#include <vector>
#include <limits>
using namespace std;
// time limit!!
class mySolution {
public:
    int jump(vector<int>& nums) {
    	if(nums.size() == 1){
    		return 0;
    	}
        vector<int> dp(nums.size(), 0);
        dp[0] = 0;
        for(int i = 1; i < nums.size(); ++i){
        	int temp = INT_MAX;
        	for(int j = 0; j < i; ++j){
        		if(j + nums[j] >= i){
        			if(dp[j] + 1 < temp){
        				temp = dp[j] + 1;
        			}
        		}
        	}
        	dp[i] = temp;
        }
        return dp[nums.size()-1];
    }
};
// time limit still
class anotherSolution {
public:
    int jump(vector<int>& nums) {
    	vector<int> record(nums.size(), 0);
    	record[0] = 0;
        for(int i = 0; i < record.size(); ++i){
        	if(i+nums[i] >= nums.size()-1){
        		return record[i] + 1;
        	}
        	for(int j = i + 1; j <= i + nums[i] && j < record.size(); ++j){
        		if(record[j] == 0){
        			record[j] = record[i] + 1;

        		}
        	}
        }
        return 0;
    }
};

//best
class Solution {
public:
    int jump(vector<int>& nums) {
   		int count = 0;
   		int begin = 0;
   		int end = 0;
   		if(nums.size() == 1){
   			return 0;
   		}
   		while(begin <= end){
   			int max = 0;
   			count++;
   			for(int i = begin; i <= end; ++i){
   				if(nums[i] + i > max){
   					max = nums[i] + i;
   				}
   				if(max >= nums.size()-1){
   					return count;
   				}
   			}
   			begin = end + 1;
   			end = max;

   		}

   		return -1;

    }
};








