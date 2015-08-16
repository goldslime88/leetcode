#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
private: 
	vector<int> ans;
public:
    vector<int> grayCode(int n) {
        try{
        	if( n < 1){
        		throw 0;
        	}
        }
        catch(int e){
        	ans.push_back(0);
        	cout<<"wrong n"<<endl;
        	return ans;
        }
        for(int i = 1; i <= n; ++i){
        	if( i == 1){
        		ans.push_back(0);
        		ans.push_back(1);
        	}
        	else{
        		for(int j = ans.size()-1; j >= 0; --j){
        			ans.push_back(ans[j]);

        		}
        		int num = pow(2,i-1);
        		for(int j = ans.size()/2; j < ans.size(); j++){
        			ans[j] = ans[j] + num;

        		}
        	}
        }
        return ans;
    }

};