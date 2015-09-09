#include <vector>
#include <iostream>
#include <limits>
#include <complex>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < dp.size(); ++i){
        	int min = INT_MAX;
        	for(int j = 1; j <= sqrt(i); ++j){
        		int temp = dp[i-j*j] + 1;
        		if(temp < min){
        			min = temp;
        		}
        	}
        	dp[i] = min;
        }
        return dp[dp.size()-1];
    }
};

