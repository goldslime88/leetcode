#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map< string , vector<string> > record;
        for(int i = 0; i < strs.size(); ++i){
        	string temp = strs[i];
        	sort(temp.begin(),temp.end());
        	unordered_map< string , vector<string> >::iterator it = record.find(temp);
        	if(it == record.end()){
        		vector<string> tempV;
        		tempV.push_back(strs[i]);
        		record[temp]=tempV;
        	}
        	else{
        		record[temp].push_back(strs[i]);

        	}
        }
        vector<string> ans;
        for(unordered_map< string , vector<string> >::iterator itRc = record.begin(); itRc != record.end(); itRc++){
        	if((itRc->second).size() > 1){
        		for(int i = 0; i < (itRc->second).size(); ++i){
        			ans.push_back((itRc->second)[i]);
        		}
        	}
        }

        return ans;

    }
};