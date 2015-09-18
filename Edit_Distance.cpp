#include <iostream>
#include <string>
#include <vector>
using namespace std;
//dp
//dp[i][j] the distance between 0~i in word1 and 0~j in word2 (0 means no word)
//For each i = 1…M
//For each j = 1…N
//min of three
//D(i-1,j) + 1
//D(i,j)= min D(i,j-1) + 1
//D(i-1,j-1) + 1; if X(i) ≠ Y(j)
//             0; if X(i) = Y(j)
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector< vector<int> > dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        dp[0][0] = 0;
        for(int i = 1; i < dp.size(); ++i){
        	dp[i][0] = i;
        }
        for(int j = 1; j < dp[0].size(); ++j){
        	dp[0][j] = j;
        }
        for(int i = 1; i < dp.size(); ++i){
        	for(int j = 1; j < dp[0].size(); ++j){
        		if(word1[i-1] == word2[j-1]){
        			dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1]);
        		}
        		else{
    				dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1]+1);
        		}
        		
          	}
        }
        return dp[word1.size()][word2.size()];
    }
};