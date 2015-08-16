#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	Solution(){}
    vector<int> getRow(int rowIndex) {
    	vector<int> ans;
    	vector<int> preAns;
    	ans.push_back(1);
    	if(rowIndex == 0){
    		return ans;
    	}
    	preAns = ans;

        for(int j = 1; j <= rowIndex; ++j){
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
        }

    return ans;

        
    }
};

int main(){
    Solution* a;
    a = new Solution();
    vector<int> result;
    result = a->getRow(6);
    for(int i=0;i<result.size();++i){
        cout<< result[i]<<" ";
    }
    cout<<endl;

}