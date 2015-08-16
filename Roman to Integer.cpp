#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int sum = 0;
    	stack<char>  charStack; 
    	for(int i = 0; i < s.size(); ++i){
    		if(charStack.empty()){
    			charStack.push(s[i]);
    		}
    		else if(ctoi(charStack.top())>=ctoi(s[i])){
    			sum += ctoi(charStack.top());
    			charStack.pop();
    			charStack.push(s[i]);

    		}
    		else{
    			sum += ctoi(s[i])-ctoi(charStack.top());
    			charStack.pop();
    		}

    	}

    	if(!charStack.empty()){
    		sum += ctoi(charStack.top());
    	}

    	return sum;

        
    }
    int ctoi(char c){
    	switch(c){
    		case 'I': return 1;
    		case 'V': return 5;
    		case 'X': return 10;
    		case 'L': return 50;
    		case 'C': return 100;
    		case 'D': return 500;
    		case 'M': return 1000;
    		default: return 0;
    	}
    }


};

int main(){
	Solution* a;
	a = new Solution();
	cout<<a->romanToInt("XX")<<endl;

}