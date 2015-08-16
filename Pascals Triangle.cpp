#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector< vector<int> > result;
    	vector<int> ans;
    	vector<int> preAns;
    	if(numRows == 0){
    		return result;
    	}
    	numRows = numRows -1;
    	ans.push_back(1);
    	result.push_back(ans);
    	if(numRows == 0){
    		return result;
    	}
    	preAns = ans;

        for(int j = 1; j <= numRows; ++j){
        	for(int i = 0; i < j; ++i){
        		if( i == 0 ){
                    ans[i] = 1;
                }
                else{
                    ans[i] = preAns[i-1] + preAns[i];
                }
            }
            ans.push_back(1);
            preAns = ans;
            result.push_back(ans);
        }

        return result;
        
    }
};