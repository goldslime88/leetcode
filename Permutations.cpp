#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        recurPermute(nums, 0);
        return ans;
    }
    void recurPermute( vector<int>& nums, int index ) {
    	if(index >= nums.size()){
    		ans.push_back(nums);
    		return;
    	}

    	for(int i = index; i < nums.size(); ++i){
    		swap(nums[index], nums[i]);
    		recurPermute(nums, index+1);
    		swap(nums[index], nums[i]);
    	}
    }
private:
	vector< vector<int> > ans;
};