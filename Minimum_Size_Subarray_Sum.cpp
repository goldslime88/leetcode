#include <iostream>
#include <vector>
#include <limits>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int head = 0;
        int tail = -1;
        bool enlarge = true;
        int min = INT_MAX;
        int cur_sum = 0;
        int cur_size = 0;
        bool find_one = false;
       	int nums_size = nums.size();
        while(tail < nums_size-1){
        	
        	if(enlarge && tail < nums_size-1){
        		++tail;
        		cur_sum = cur_sum + nums[tail];
        		++ cur_size;
        		if(cur_sum >= s){
        			if(cur_size < min){
        				min = cur_size;
        			}
        			enlarge = false;
        			find_one = true;
        			if(min == 1){
        				return 1;
        			}
        		}
        	}
        	if(!enlarge && cur_size > 1){
        		cur_sum = cur_sum - nums[head];
        		++head;
        		--cur_size;
        		if(cur_sum < s){
        			enlarge = true;
        		}
        		if(cur_sum >= s){
        			if(cur_size < min){
        				min = cur_size;
        			}
        			find_one = true;
        			if(min == 1){
        				return 1;
        			}
        		}
        	}
        }

        while(head <= tail){
        	cur_sum = cur_sum - nums[head];
        	++head;
        	--cur_size;
        	if(cur_sum >= s && cur_size < min){
        		min = cur_size;
        	}
        	if(cur_sum < s){
        		break;
        	}
        }

    	if(!find_one){
    		return 0;
    	}
    	else{
    		return min;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {1,4,4};
	s->minSubArrayLen(4, test);
	return 0;
}