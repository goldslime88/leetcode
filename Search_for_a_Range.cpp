#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        double d_target = target;
        double low_target = d_target - 0.5;
        double high_target = d_target + 0.5;
        vector<int> ans(2,-1);
        //find lower boundary
        int i = 0, j = nums.size()-1;
        while(i <= j){
        	int mid = (i + j)/2;
        	if(((double)nums[mid]) < low_target ){
        		i = mid + 1;
        	}
        	else if(((double)nums[mid]) > low_target){
        		j = mid - 1;
        	}
        }
        int lower_index = i;
        i = 0;
        j = nums.size()-1;
        while(i <= j){
        	int mid = (i + j)/2;
        	if(((double)nums[mid]) < high_target ){
        		i = mid + 1;
        	}
        	else if(((double)nums[mid]) > high_target){
        		j = mid - 1;
        	}
        }
        int high_index = j;
        cout<<lower_index << " "<< high_index<<endl;
        if(lower_index > high_index){
        	return ans;
        }

	    ans[0] = lower_index;
	    ans[1] = high_index;       	
        
	    cout<<ans[0]<<ans[1]<<endl;
        return ans;

    }
};

int main(int argc, char const *argv[])
{
	vector<int> test(2,2);
	Solution* s = new Solution();
	s->searchRange(test, 2);
	return 0;
}