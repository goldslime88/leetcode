#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//think like 2^n, actually itis like sth^n
class Solution {
public:
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> number;
        vector<int> fre;
        for(int i = 0; i < nums.size(); ++i){
        	if(i == 0){
        		number.push_back(nums[i]);
        		fre.push_back(1);
        		continue;
        	}
        	if(nums[i] == number[number.size()-1]){
        		fre[fre.size()-1] ++;
        	}
        	else{
        		number.push_back(nums[i]);
        		fre.push_back(1);
        	}
        }
        vector<int> subset;

        recurSub(number, fre, 0, subset);
        return ans;


    }

    void recurSub(vector<int>& number, vector<int>& fre, int index, vector<int>& subset){
    	if(index >= number.size()){
    		ans.push_back(subset);
    		return;
    	}

    	int key = number[index];
    	int val = fre[index];

    	for(int i = 0; i <= val; ++i){
    		for(int j = 0; j < i; ++j){
    			subset.push_back(key);
    		}
    		
    		recurSub(number, fre, index+1, subset);
    		for(int j = 0; j < i; ++j){
    			subset.pop_back();
    		}
    		

    	}


    }


private:
	vector< vector<int> > ans;
};



int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {0};
	s->subsetsWithDup(test);
	return 0;
}