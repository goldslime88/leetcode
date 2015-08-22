#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
//my solution back_tracking exceed time_limit
class mySolution {
public:
	mySolution(){
		max = INT_MAX;
	}
    int minPathSum(vector< vector<int> >& grid) {
        recurMin(grid, 0, 0, grid[0][0]);
        return max;
    }
    void recurMin(vector< vector<int> >& grid, int right, int down, int val){
    	if(right == grid[0].size()-1 && 
    		down == grid.size()-1){
    		if(val < max){
    			max = val;
    		}
    		return;
    	}
    	if(right < grid[0].size()-1){
    		recurMin(grid, right+1, down, val + grid[down][right+1]);

    	}
    	if(down < grid.size()-1){
    		recurMin(grid, right, down+1, val + grid[down+1][right]);

    	}
    }


private:
	int max; 
};
//dp is much better
class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        vector< vector<int> > record (grid.size(), vector<int>(grid[0].size(), 0));
        record[0][0] = grid[0][0]; 
        for(int i = 1 ; i < record.size(); ++i){
        	record[i][0] = record[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < record[0].size(); ++i){
        	record[0][i] = record[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < record.size(); ++i){
        	for(int j = 1; j < record[0].size(); ++j){
        		record[i][j] = record[i-1][j]>record[i][j-1]?(record[i][j-1]+grid[i][j]):(record[i-1][j]+grid[i][j]);
        	}
        }

        return record[record.size()-1][record[0].size()-1];

    }
};