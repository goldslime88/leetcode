#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

       if(numbers.size() < 2){
       	    vector<int> ans;
       	    return ans;
       }
       int i = 0;
       int j = numbers.size() - 1;
       while(i < j){
       		if(numbers[i] + numbers[j] == target){
       			vector<int> ans = { i + 1, j + 1 };

       			return ans;
       		}
       		else if(numbers[i] + numbers[j] < target){
       			++i;
       		}
       		else{
       			--j;
       		}
       } 
    }
};