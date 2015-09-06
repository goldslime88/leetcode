#include <iostream>
#include <vector>
using namespace std;

//time too long 
class mySolution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int total_row = obstacleGrid.size();
        int total_col = obstacleGrid[0].size();
        recurPath(obstacleGrid, 0, 0, total_row-1, total_col-1);
        return count;
    }

    void recurPath(vector< vector<int> >& obstacleGrid, int now_row, int now_col,
    	int total_row, int total_col){
    	if(obstacleGrid[now_row][now_col] == 1){
    		return;
    	}
    	if(now_col == total_col && now_row == total_row){
    		count++;
    		return;
    	}

    	if(now_row < total_row){
    		recurPath(obstacleGrid, now_row+1, now_col, total_row, total_col);
    	}

    	if(now_col < total_col){
    		recurPath(obstacleGrid, now_row, now_col+1, total_row, total_col);
    	}


    }

private:
	int count;
};

//dp
class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {

		int rows = obstacleGrid.size();
		int cols = obstacleGrid[0].size();
		vector< vector<int> > dp (rows, vector<int>(cols, 0));
		for(int i = 0; i < rows; ++i){
			if(obstacleGrid[i][0] == 1){
				break;
			}
			else{
				dp[i][0] = 1;
			}
		}       
		for(int i = 0; i < cols; ++i){
			if(obstacleGrid[0][i] == 1){
				break;
			}
			else{
				dp[0][i] = 1;
			}
		}
		for(int i = 1; i < rows; ++i){
			for(int j = 1; j < cols; ++j){
				if(obstacleGrid[i][j] == 1){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
			}
		}

		return dp[rows-1][cols-1];
    }
};
















