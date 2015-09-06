#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
        	return 0;
        }
        unordered_map< int, int > record;
        int longest = 1;
        //head and tail is right, inside is wrong but we dont care
        //using erase will have duplicaste problems
        for(int i = 0; i < nums.size(); ++i){
        	if(record.find(nums[i]) != record.end() ){
        		continue;
        	}
        	if(record.find(nums[i]-1) == record.end() && record.find(nums[i]+1) == record.end()){
        		record[nums[i]] = 1;
        		continue;
        	}
        	if(record.find(nums[i]-1) != record.end() && record.find(nums[i]+1) == record.end()){
    			int size = record[nums[i]-1];
    			record[nums[i]-size] = size + 1;
    			record[nums[i]] = size + 1;
    			if(size + 1 > longest){
    				longest = size + 1;
    			}
        		continue;
        	}
        	if(record.find(nums[i]-1) == record.end() && record.find(nums[i]+1) != record.end()){


    			int size = record[nums[i]+1];
    			record[nums[i]+size] = size + 1;
    			record[nums[i]] = size + 1;

    			if(size + 1 > longest){
    				longest = size + 1;
    			}
        		
        		continue;
        	}
        	if(record.find(nums[i]-1) != record.end() && record.find(nums[i]+1) != record.end()){
        		int size_head = record[nums[i]-1];
        		int size_tail = record[nums[i]+1];
        		record[nums[i] - size_head] = size_head + 1 + size_tail;
        		record[nums[i] + size_tail] = size_head + 1 + size_tail;
        		//next line is very important!!!!!
        		//otherwise, duplicated will count twice
        		record[nums[i]] = size_head + 1 + size_tail;
        		if(size_head + 1 + size_tail > longest){
        			longest = size_head + 1 + size_tail;
        		}
        		continue;
        	}
        }

        return longest;

    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> test = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
	cout<< s->longestConsecutive(test)<<endl;
	return 0;
}