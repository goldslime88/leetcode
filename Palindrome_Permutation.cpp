#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    bool canPermutePalindrome(string s) {
    	vector<int> record(128,0);
    	for(int i = 0; i < s.size(); ++i){
    		record[(int)(s[i])]++;
    	}

    	if(s.size()%2 == 0){
    		for(int i = 0; i < record.size(); ++i){
    			if(record[i]%2 != 0){
    				return false;
    			}
    		}
    	}   
    	else{
    		bool flag = false;
    		for(int i = 0; i < record.size(); ++i){
    			if(record[i]%2 != 0){
    				if(!flag){
    					flag = true;
    				}
    				else{
    					return false;
    				}
    			}
    		}
    	} 
    	return true;
    }
};