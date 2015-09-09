#include <iostream>
#include <string>
#include <vector>
using namespace std;

//exceed time limit
class MySolution {
public:
    int numDistinct(string s, string t) {
        ans = 0;
        recurFind(s ,t, 0, 0);
        return ans;
    }

    void recurFind(const string &s, const string &t, int s_index, int t_index){
    	if(t_index == t.size()){
    		ans++;
    		return;
    	}
    	if(s_index == s.size()){
    		return;
    	}

    	for(int i = s_index; i < s.size(); ++i){
    		if(s[i] == t[t_index]){
    			recurFind(s, t, i+1, t_index+1);
    		}
    	}


    }
private:
	int ans;
};
//dp
class Solution {
public:
    int numDistinct(string s, string t) {
    	if(s.empty()){
    		return 0;
    	}
        vector< vector<int> > dp(s.size(), vector<int>(t.size(), 0));
        int temp_sum = 0;
        for(int i = 0; i < s.size(); ++i){       	
        	if(s[i] == t[0]){
        		++temp_sum;
        	}
        	dp[i][0] = temp_sum;
        }
        for(int j = 1; j < t.size(); ++j){
        	for(int i = j; i < s.size(); ++i){

        		if(s[i] != t[j]){
        			dp[i][j] = dp[i-1][j];
        		}
        		else{
        			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        		}
        	}
        }

        return dp[s.size()-1][t.size()-1];
    }
};



int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<< s->numDistinct("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac", "ceadbaa")<<endl;
	return 0;
}