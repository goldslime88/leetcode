#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	if(citations.empty()){
    		return 0;
    	}
        sort(citations.begin(), citations.end());
        int size = citations.size();
        int record = citations[citations.size()-1];
        int i;
        for(i = 0; i < size; ++i){
        	if(citations[i] >= size - i){
        		record = i;
        		break;
        	}
        }
        if(i < size){
        	return size - record;        	
        }
        else{
        	return record;
        }

    }
};


int main(int argc, char const *argv[])
{
	Solution* s = new Solution();
	vector<int> test = {3,0,6,1,5};

	return 0;
}