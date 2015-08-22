#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> record;
        for( int i = 0; i < nums.size(); ++i )
        {
        	if(record.find(nums[i]) == record.end())
        	{
        		record.insert(nums[i]);
        	}
        	else
        	{
        		record.erase(nums[i]);
        	}
        }
        set<int>::iterator it = record.begin();
        vector<int> ans;
        ans.push_back(*it);
        ans.push_back(*(++it));
        return ans;
    }
};