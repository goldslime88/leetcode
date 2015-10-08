#include <vector>
#include <algorithm>
#include <limits>
using namespace std;


class Solution {
public:
    int minCostII(vector< vector<int> >& costs) {
    	if(costs.empty()){
    		return 0;
    	}
        if(costs.size() == 1){
        	int min = INT_MAX;
        	for(int i = 0; i < costs[0].size(); ++i){
        		if(costs[0][i] < min){
        			min = costs[0][i];
        		}
        	}
        	return min;
        }
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int i = 0; i < costs[0].size(); ++i){
    		if(costs[0][i] < min1 && ){
    			min = costs[0][i];
    		}
    	}
        for(int i = 1; i < costs.size(); ++i){

        }
    }


   	void pickMins(vector< vector >)
};