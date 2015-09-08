#include <iostream>
#include <vector>
#include <string>
using namespace std;

//substr(begin index, count);
class Solution {
public:
    vector< vector<string> > partition(string s) {
      	vector< vector< vector<string> > >  ans;
      	if(s == ""){
      		vector< vector<string> > empty;
      		return empty;
      	}
      	string first_string(1, s[0]);
      	vector<string> first(1,first_string);
      	vector< vector<string> > combine;
      	combine.push_back(first);
      	ans.push_back(combine);


      	for(int i = 1; i < s.size(); ++i){
      		vector< vector<string> > now;
      		//add only one
      		for(int j = 0; j < ans[i-1].size(); ++j){
      			vector<string> temp(ans[i-1][j]);
      			string char_to_s(1, s[i]);
      			temp.push_back (char_to_s);
      			now.push_back(temp);
      		}
      		//add not only one
      		for(int j = i-1; j >= 0; --j){
      			string sub_string = s.substr(j,i+1-j);

      			if(isPalindrome(sub_string)){
      				if(j > 0){
      					for(int k = 0; k < ans[j-1].size(); ++k){
      						vector<string> temp(ans[j-1][k]);
      						temp.push_back (sub_string);
      						now.push_back(temp);
      					}	
      				}
      				else{
      					vector<string> temp;
      					temp.push_back(sub_string);
      					now.push_back(temp);

      				}
      			}
      		}
      		ans.push_back(now);
      	}

      	return ans[ans.size()-1];
    }
    bool isPalindrome (string s){
    	int i = 0, j = s.size() - 1;
    	while(i<j){
    		if(s[i] != s[j]){
    			return false;
    		}
    		++i;
    		--j;
    	}
    	return true;
    }
};

//back tracking
class betterSolution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }

    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	string test = "abbab";
	vector< vector<string> > ans;
	ans = s->partition(test);
	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}