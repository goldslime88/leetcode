#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//using dq, O(N)
//maintain a deque back(small) -> front(large), when meet ai, pop all back 
//smaller than ai and push ai to back. one problem, some element may out of 
//the window, we only care first one in front. Check front if not in window, pop
//it until we find the first one
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
        	while(!dq.empty() && nums[dq.back()] <= nums[i]){
        		dq.pop_back();
        	}
        	dq.push_back(i);
        	while(!dq.empty() && dq.front() <= i-k){
        		dq.pop_front();
        	}

        	if(i >= k-1){
        		ans.push_back(nums[dq.front()]);
        	}


        }

        return ans;
    }
};