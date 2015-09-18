#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int last = nums.size() - 1;
        int down = nums.size();
        for(int i = last; i > 0; --i){
        	if( nums[i] > nums[i-1] ){
        		down = i;
        		break;
        	}
        }
        
        if(down == nums.size()){
        	sort(nums.begin(), nums.end());
        }
        else{
        	
        	//find the minimum in that subarray that larger than down -1
        	int index = -1;
        	int num = INT_MAX;
        	for(int i = down; i < nums.size(); ++i){
        		if(nums[i] > nums[down-1] && nums[i] < num){
        			num = nums[i];
        			index = i;
        		}
        	}
        	int temp = nums[index];
        	nums[index] = nums[down-1];
        	nums[down-1] = temp;
        	sort(nums.begin()+down, nums.end());
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {2,3,1};
	s->nextPermutation(test);
	for(int i = 0; i < test.size(); ++i){
		cout<<test[i]<<endl;
	}
	return 0;
}