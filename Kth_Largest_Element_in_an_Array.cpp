#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class compare{
public:
	bool operator ()(const int& a, const int& b){
		return a > b;
	}
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, compare> pq;
        for(int i = 0; i < nums.size(); ++i){
        	if(pq.size()<k){
        		pq.push(nums[i]);
        	}
        	else{
        		pq.push(nums[i]);
        		pq.pop();
        	}
        }
        return pq.top();
    }
};