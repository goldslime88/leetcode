#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> word_index(words.size(), 0);
        
        for(int i = 0; i < words.size(); ++i){
        	if(words[i] == word1){
        		word_index[i] = 1;
        	}
        	if(words[i] == word2){
        		word_index[i] = 2;
        	}
        }

        int min = words.size();
        int nearest1 = -1;
        int nearest2 = -1;
        for(int i = 0; i < words.size(); ++i){
        	if(word_index[i] == 1){
        		if(nearest2 != -1){
        			int temp = i - nearest2;
        			if(temp < min){
        				min = temp;
        			}
        		}
        		nearest1 = i;
        	}
        	if(word_index[i] == 2){
        		if(nearest1 != -1){
        			int temp = i - nearest1;
        			if(temp < min){
        				min = temp;
        			}
        		}
        		nearest2 = i;
        	}

        }
        return min;
    }
};