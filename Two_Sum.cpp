#include <iostream>
#include <vector>
#include <unordered_map>	
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	unordered_map<int, int> record;
    	vector<int> ans;
    	for(int i = 0; i < numbers.size(); ++i){
    		int num = target - numbers[i];
    		unordered_map<int, int>::iterator it;
    		it = record.find(numbers[i]);

    		if(it == record.end()){
    			record[num] = i;

    		}
    		else{
    			ans.push_back(it->second+1);
    			ans.push_back(i+1);
    		}
    	
    	
    		
    	}

    	return ans;
    	        
    }
};

int main(){
	Solution* a;
	a = new Solution();
	vector<int> num;
	num.push_back(3);
	num.push_back(2);
	num.push_back(4);
	vector<int> ans;
	ans = a->twoSum(num,6);
	cout<<ans.size()<<endl;
	cout<<ans[0]<<ans[1]<<endl;

}