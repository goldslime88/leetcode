#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        int temp = n;
        string ans = "";
        vector<char> num_remain;
        for(int i = 0; i < n; ++i){
        	num_remain.push_back((char)(i+'1'));
        }

        while(temp>0){
        	int num = (k-1)/factor(temp-1);
        	char tchar = num_remain[num];
        	num_remain.erase(num_remain.begin()+num);
        	ans = ans + tchar;
        	k = k%factor(temp-1);
        	if(k==0){
        		k = factor(temp-1);
        	}
        	--temp;

        }
        
        return ans;
    }

    int factor(int n){
    	int temp = n;
    	int ans = 1;
    	while(temp>0){
    		ans = ans * temp;
    		--temp;
    	}

    	return ans;
    }
};