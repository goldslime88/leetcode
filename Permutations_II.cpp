#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > ans;
        sort(nums.begin(), nums.end());
        recurPermute(ans, nums, 0);
        return ans;
    }
    void recurPermute(vector< vector<int> >& ans, vector<int>& nums, int index){
    	if(index >= nums.size()) {
    		ans.push_back(nums);
    		return;
    	}
    	set<int> record;
    	for(int i = index; i < nums.size(); ++i){
    		if(record.find(nums[i]) != record.end()){
    			continue;
    		}
    		else{
    			record.insert(nums[i]);
    		}
    		swap(nums[i], nums[index]);	
    		recurPermute(ans, nums, index+1);
    		swap(nums[i], nums[index]);
    	}

    }
};

int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	vector<int> test = {1,1,0,0,1,-1,-1,1};
	s->permuteUnique(test);
	return 0;
}
