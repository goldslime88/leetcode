#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector<int> temp;
        recurCombine(temp, n, k, 1);
        return ans;
        
    }
    void recurCombine(vector<int>& combine_now, int n, int k, int lead_num){
    	if(combine_now.size() == k){
    		ans.push_back(combine_now);
    		return;
    	}

    	for( int i = lead_num; i <= n; ++i ){
    		combine_now.push_back(i);
    		recurCombine(combine_now,n,k,i+1);
    		combine_now.pop_back();
    	}
    	return;
    }
private:
	vector< vector<int> > ans;
};

int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	vector< vector<int> > ans = s->combine(4,2);
	for(int i = ans.)
	return 0;
}