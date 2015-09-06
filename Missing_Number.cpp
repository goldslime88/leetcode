#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int last = nums.size();
        int j = 0;
        for(int i = 0; i < nums.size(); ++i){
        	res = res ^ nums[i];
        	res = res ^ j;
        	j++;
        }
        res = res ^ last;
        return res;
    }
};