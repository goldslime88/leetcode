#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1 == s2){
    		return true;
    	}
    	vector<int> record_al(26,0);
    	int size = s1.size();
    	for(int i = 0; i < size; ++i){
    		record_al[s1[i] - 'a']++;
    		record_al[s2[i] - 'a']--;
    	}
    	for(int i = 0; i < 26; ++i){
    		if(record_al[i] != 0){
    			return false;
    		}
    	}

    	for(int i = 1; i < size; ++i){
    		if(isScramble(s1.substr(0,i), s2.substr(0,i)) && 
    			isScramble(s1.substr(i), s2.substr(i))){
    			return true;
    		}
    		if(isScramble(s1.substr(0,i), s2.substr(size-i)) &&
    			isScramble(s1.substr(i), s2.substr(0, size-i))){
    			return true;
    		}
    	}

    	return false;

    }
};

