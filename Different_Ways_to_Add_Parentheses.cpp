#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	bool is_number = true;
    	vector<int> res;
    	for(int i = 0; i < input.size(); ++i){
    		if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
    			is_number = false;
    			string left = input.substr(0 , i);
    			string right = input.substr(i+1, input.size() - i - 1);
    			vector<int> left_res = diffWaysToCompute(left);
    			vector<int> right_res = diffWaysToCompute(right);
    			for(int left_i = 0; left_i < left_res.size(); ++left_i){
    				for(int right_i = 0; right_i < right_res.size(); ++right_i){
    					if(input[i] == '+'){
    						res.push_back(left_res[left_i] + right_res[right_i]);
    					}
    					else if(input[i] == '-'){
    						res.push_back(left_res[left_i] - right_res[right_i]);
    					}
    					else{
    						res.push_back(left_res[left_i] * right_res[right_i]);
    					}
    				}
    			}   			
    		}
    	}
    	if(is_number){
    		int temp = stoi(input);
    		res.push_back(temp);
    	}
    	return res;
    }

private:
	vector<int> ans;
};