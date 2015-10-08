#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
struct 
{
	bool operator()(Interval a, Interval b){
		a.start < b.start;
	}
} IntervalLess;
//sort method
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), IntervalLess);
        if(intervals.empty()){
        	return intervals;
        }
        if(intervals.size() == 1){
        	return intervals;
        }
        vector<Interval> ans;
        int start = 0;
        int cur = 1;
        while(cur < intervals.size()){
        	if(intervals[start].end >= intervals[cur].end){
        		//eat it
        	}
        	else if(intervals[start].end >= intervals[cur].start && 
        		intervals[start].end < intervals[cur].end){
        		intervals[start].end = intervals[cur].end;
        		
        	}
        	else if(intervals[start].end < intervals[cur].start){
        		ans.push_back(intervals[start]);
        		start = cur;
        	}
        	++cur;
        }
        if(start != cur){
        	ans.push_back(intervals[start]);
        }
        return ans;
    }
};

//time limit exceed
class mySolution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        
        for(int i = 0; i < intervals.size(); ++i){
        	bool insert = false;
        	vector<int> intervals_to_delete;
        	Interval temp(intervals[i].start, intervals[i].end);
        	for(int j = 0; j < ans.size(); ++j){
        		if(temp.start <= intervals[j].end && temp.start >= intervals[j].start
        			&& temp.end >= intervals[j].end){
        			intervals_to_delete.push_back(j);
        			temp.start = intervals[j].start;
        			insert = true;
        		}
        		else if(temp.end >= intervals[j].start && temp.end <= intervals[j].end
        			&& temp.start <= intervals[j].start){
     
        			intervals_to_delete.push_back(j);
        			temp.end = intervals[j].end;
        			insert = true;
        		}
        		else if(temp.end >= intervals[j].end && temp.start <= intervals[j].start){
        			intervals_to_delete.push_back(j);
        			insert = true;
        		}
        		else if(temp.end <= intervals[j].end && temp.start >= intervals[j].start){
        			

        		}
        		else{
        			insert = true;
        		}
        	}

        	for(int k = 0; k < intervals_to_delete.size(); ++k){
        		ans.erase(ans.begin()+intervals_to_delete[k]-k);
        	}
        	

        	if(insert || ans.empty()){
        		ans.push_back(temp);
        	}
        	
        }

        return ans;
    }
};



int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	Interval a(1,4), b(0,2), c(3,5);
	vector<Interval> test;
	test.push_back(a);
	test.push_back(b);
	test.push_back(c);
	s->merge(test);
	return 0;
}