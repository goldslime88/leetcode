#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

	Solution(){}
    string convert(string s, int nRows) {
    	vector<string> record;
    	string ans = "";
    	if(nRows == 1){
    		return s;
    	}
    	
    	for(int i = 0; i < nRows; ++i){
    		string temp = "";
    		record.push_back(temp);
    	}
        for(int i = 0; i < s.size(); ++i){
        	int mod = i % (2*nRows - 2);
        	if(mod < nRows){
        		record[mod] = record[mod] + s[i];
        	}
        	else{
        		record[2*nRows-2-mod] = record[2*nRows-2-mod] + s[i];
        	}

        	
        	
        }

        for(int i = 0; i < nRows; ++i){
        	ans = ans + record[i]; 
        }

        return ans;

    }
};

int main(){
	Solution* a;
	a = new Solution();
	string test= "PAYPALISHIRING";
	cout<< a->convert(test,3)<<endl;
}