#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        recurCombine(candidates, nums, 0, target, 0);
        return ans;
    }

    void recurCombine(vector<int>& candidates, vector<int>& nums, int sum, int target, int index){
    	if(sum > target){
    		return;
    	}
    	if(sum == target){
    		ans.push_back(nums);
    		return;
    	}
    	for(int i = index; i < candidates.size(); ++i){
    		sum = sum + candidates[i];
    		nums.push_back(candidates[i]);
    		recurCombine(candidates, nums, sum, target, i);
    		sum = sum - candidates[i];
    		nums.pop_back();
    	} 

    }

private:
	vector< vector<int> > ans;
};