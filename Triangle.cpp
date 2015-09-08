#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//brute force
class mySolution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
        mini = INT_MAX;
        int level = triangle.size();
        recurMin(triangle, 0, 0, level);
        return mini;

    }
    void recurMin(vector< vector<int> >& triangle, int sum_now, int level_now, int level){
    	if(level_now>= level){
    		if(sum_now < mini){
    			mini = sum_now;
    		}
    		return;
    	}

    	for(int i = 0; i <= level_now; ++i){
    		sum_now = sum_now + triangle[level_now][i];
    		recurMin(triangle, sum_now, level_now+1, level);
    		sum_now = sum_now - triangle[level_now][i];
    	}
    	return;
    }

private:
	int mini;

};

class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
    	int ans = INT_MAX;
        vector< vector<int> > dp;
        for(int i = 1; i <= triangle.size(); ++i){
        	vector<int> temp(i, 0);
        	dp.push_back(temp);
        }
        dp[0][0] = triangle[0][0];
        if(triangle.size() == 1){
        	return dp[0][0];
        }
        for(int i = 1; i < dp.size(); ++i){
        	for(int j = 0; j <= i; ++j ){
        		if(j == 0){
        			dp[i][j] = dp[i-1][j] + triangle[i][j];

        		}
        		else if(j == i){
        			dp[i][j] = dp[i-1][j-1] + triangle[i][j];


        		}
        		else{
        			dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];


        		}
    	       	if( i == dp.size()-1){
    				if(dp[i][j] < ans){
    					ans = dp[i][j];
    				}
    			}
        		
        	}

        }
        return ans;


    }
};










