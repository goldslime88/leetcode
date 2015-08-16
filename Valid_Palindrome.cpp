#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	Solution(){}
    bool isPalindrome(string s) {
    	int i = 0;
    	int j = s.size() - 1;
    	while(i!=j && j-i > 0){
    		while((!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')))&&(i < s.size())){
    			i++;       
    		}
    		while((!((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')||(s[j]>='0'&&s[j]<='9')))&&(j >= 0)){
    			j--;                
    		}
            if(i > j){
                return true;
            }
    		if(s[i] == s[j] || s[i] == s[j] - 'a' + 'A' || s[i] == s[j] - 'A' +'a'){
                i++;
                j--;
    		}
    		else{
    			return false;
    		}
    	}
		return true;        
    }
};

int main(){
	Solution* a;
	a= new Solution();
	cout<< a->isPalindrome("ab2a") << endl;
}