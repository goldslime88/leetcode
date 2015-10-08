#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        for(int i = 0; i < s.size(); ++i){
        	if(wordDict.find(s.substr(0, i+1)) != wordDict.end()){
        		dp[i] = true;
        	}
        	else{
        		for(int j = 0; j < i ; ++j){
        			if(dp[j]){
        				if(wordDict.find(s.substr(j+1, i-j)) != wordDict.end()){
        					dp[i] = true;
        				}
        			}
        		}
        	}
        	
        }

        return dp[s.size()-1];

    }
};