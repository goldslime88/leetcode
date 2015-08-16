#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	vector<int> ans;
    	ans.push_back(1);
    	ans.push_back(1);
    	if(n==0){
    		return 0;
    	}
    	if(n==1){
    		return 1;
    	}

    	for(int i = 2; i <= n; ++i){
    		int num = 0;
    		for(int j = 1; j <= i; ++j){
    			num = num + ans[j-1]*ans[i-j];
    		}
    		ans.push_back(num);
    		
    	}

    	return ans[n];

    	
        
    }
};

int main(){
	Solution* a;
	a = new Solution();
	cout<< a->numTrees(4)<<endl;

}