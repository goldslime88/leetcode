#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	Solution(){}
    bool isValid(string s) {
    	stack<char> charStack;

    	for(string::iterator it = s.begin(); it != s.end(); ++it){



    		if((*it)=='(' || (*it)=='[' || (*it)=='{'){
    			
    			charStack.push(*it);
    		}
    		
    		if((*it)==')' && (charStack.empty()||charStack.top() != '(')){
    			return false;
    		}
    		else if((*it)==')' && charStack.top() == '('){
    			charStack.pop();

    		}
    		if((*it)==']' && (charStack.empty()||charStack.top() != '[')){

    			return false;
    		}
    		else if((*it)==']' && charStack.top() == '['){

    			charStack.pop();
    		}


    		if((*it)=='}' && (charStack.empty()||charStack.top() != '{')){
    			return false;
    		}
    		else if((*it)=='}' && charStack.top() == '{'){
    			charStack.pop();
    		}

    	}
    	
    	if(charStack.empty()==1){
    		return true;

    	}

    	else{
    		return false;
    	}
    	
	    

	    
        
    }
};

int main(){
	Solution* a;
	a = new Solution();
	string s = "()}";
	cout<< a->isValid(s)<<endl;




}