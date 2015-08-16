#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	Solution(){}
    string longestCommonPrefix(vector<string> &strs) {
    	if(strs.empty()){
    		return "";
    	}
    	string cPrefix = strs[0];
    	for(vector<string>::iterator it = strs.begin(); it != strs.end(); ++it){
    		string temp = "";
    		for(int i = 0; i< cPrefix.size(); ++i){
    			if(((*it)[i])==cPrefix[i]){
    				temp.push_back(cPrefix[i]);
    			}
    			else{
    				break;
    			}
    		}
    		cPrefix = temp;
    	}

    	return cPrefix;
    }
};

int main(){
	Solution *a;
	a = new Solution();
	vector<string> strSet;
	strSet.push_back("a53071897");
	strSet.push_back("a53088846");
	strSet.push_back("a53111111");
	cout<<a->longestCommonPrefix(strSet)<<endl;
}