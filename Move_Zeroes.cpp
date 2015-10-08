#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for(int i = 0; i < nums.size(); ++i){

        	if(nums[i] == 0){
        		++zeros;
        	}
        	else{
        		nums[i-zeros] = nums[i];
        	}

        }

        for(int i = 0; i < zeros; ++i){
        	nums[nums.size()-1-i] = 0;
        }
    }
};



int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	vector<int> test = {0, 1, 0, 3, 12};
	s->moveZeroes(test);
	for(int i = 0; i < test.size(); ++i){
		cout<<test[i]<<endl;
	}
	return 0;
}