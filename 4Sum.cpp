#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > ans;
        if(nums.size() < 4){
            return ans;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()-3){
        	int tempi = nums[i];
        	int j = i + 1;
        	while(j < nums.size()-2){
        		int tempj = nums[j];
        		int k = j + 1;
        		int l = nums.size() - 1;
        		while(k < l){
        			int sum = tempi + tempj + nums[k] + nums[l];
        			if(sum == target){
        				vector<int> sum_set = {tempi, tempj, nums[k], nums[l]};
        				ans.push_back(sum_set);
        				k = find_next(nums, k);
        				l = find_pre(nums, l);
        			}
        			else if(sum < target){
        				++k;
        			}
        			else{
        				--l;
        			}
        		}
        		j = find_next(nums, j);
        	}
        	i = find_next(nums, i);
        }

        return ans;
    }

    int find_next(vector<int> &num, int i){
        int temp = num[i];
        ++i;
        while(i < num.size() && temp == num[i]){
            ++i;
        }
        return i;
    }

    int find_pre(vector<int> &num, int i){
        int temp = num[i];
        --i;
        while(i>=0 && temp == num[i]){
            --i;
        }
        return i;
    }
};