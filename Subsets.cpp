#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        recurSubset(nums, subset, 0);
        return ans;

    }
    void recurSubset(vector<int>& nums, vector<int>& subset, int index){
    	if(index >= nums.size()){
    		ans.push_back(subset);
    		return;
    	}
    	else{
    	subset.push_back(nums[index]);
    	recurSubset(nums,subset,index+1);
    	subset.pop_back();
    	recurSubset(nums,subset,index+1);

    	
    	return;
    	}
    }

private:
	vector< vector<int> > ans;
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {1,2,3};
	vector< vector<int> > ans = s->subsets(test);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<"[";
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout<<ans[i][j]<<",";
		}
		cout<<"]"<<endl;
	}
	return 0;
}