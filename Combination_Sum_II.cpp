#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
		vector< vector<int> > ans;
		sort(candidates.begin(), candidates.end());
		vector<int> now;
		recurCombine(candidates, target, 0, ans, 0, now);
		return ans;

    }

    void recurCombine(vector<int>& candidates, int target, int index, vector< vector<int> >& ans,
    	int sum, vector<int>& now){
    	if(sum == target){
    		ans.push_back(now);
    		return;
    	}
    	if(index >= candidates.size() || sum > target){
    		return;
    	}

    	set<int> record;
    	for(int i = index; i < candidates.size(); ++i){
    		if(record.find(candidates[i]) != record.end()){
    			continue;
    		}
    		else{
    			record.insert(candidates[i]);
    		}
    		sum = sum + candidates[i];
    		now.push_back(candidates[i]);
    		recurCombine(candidates, target, i+1, ans, sum, now);
    		sum = sum - candidates[i];
    		now.pop_back();
    	}
    }
};