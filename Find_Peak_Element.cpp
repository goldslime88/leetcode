#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
    	if(num.size() == 1){
    		return 0;
    	}
    	for(int i = 0; i < num.size(); ++i){
    		if(i == 0){
    			if(num[0] > -1 && num[0]>num[1]){
    				return 0;
    			}
    		}
    		if(i == num.size()-1){
    			if(num[i]>num[i-1]){
    				return i;
    			}
    		}
    		if(num[i]>num[i-1] && num[i]>num[i+1]){
    			return i;
    		}

    	}
        
    }
};