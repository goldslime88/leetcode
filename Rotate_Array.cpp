#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int num = k%(nums.size());
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, num-1);
        reverse(nums, num, nums.size()-1);
    }
    void reverse(vector<int>& nums, int head, 
    	int tail){
    	for (int i = 0; i < (tail-head)/2.0; ++i)
    	{
    		int temp = nums[i + head];
    		nums[i + head] = nums[ tail - i];
    		nums[tail-i] = temp;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	s->rotate(test,1);
	cout<<test[0]<<test[1]<<endl;
	return 0;
}