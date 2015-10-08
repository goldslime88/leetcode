#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        
        int begin = 0;
        unordered_map< char, int > record;
        for(int i = 0; i < s.size(); ++i){
        	char temp = s[i];
        	if(record.find(temp) == record.end()){
        		record[temp] = i;
        	}
        	else{
        		int index = record[temp];
        		for(int j = begin; j < index; ++j){
        			record.erase(s[j]);
        		}
        		record[temp] = i;
        		begin = index + 1;

        	}

        	int length = i - begin + 1;
        	if(length > max){
        		max = length;
        	}
        }

        return max;

    }
};