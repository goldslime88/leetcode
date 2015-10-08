#include <iostream>
#include <vector>
using namespace std;

//dfs method
class Solution {
public:
    int numIslands(vector< vector<char> >& grid) {
    	int count = 0;
        for(int i = 0; i < grid.size(); ++i){
        	for(int j = 0; j < grid[0].size(); ++j){
        		if(grid[i][j] == '1'){
        			++count;
        			clearIsland(grid, i, j);
        		}
        	}
        }
        return count;
    }

    void clearIsland(vector< vector<char> >& grid, int i, int j){
    	if(i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1 || grid[i][j] == '0'){
    		return;
    	}
    	grid[i][j] = '0';
    	clearIsland(grid, i-1, j);
    	clearIsland(grid, i+1, j);
    	clearIsland(grid, i, j-1);
    	clearIsland(grid, i, j+1);

    }
};