#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	Solution(){}
    bool isPalindrome(int x) {
    	int temp = x;
    	if(x<0){
    		return false;
    	}

    	int n=0;
    	while(temp != 0){
    		temp = temp/10;
    		n++;
    	}
    	if(n==2){
    		if(x/10 == x%10){
    			return true;
    		}
    		else{
    			return false;
    		}
    	}
        
        for(int i = 1, j = n; (i != j && j-i > 1); i++, j-- ){
        	if(x%(int)pow(10,i)/(int)pow(10,i-1) != x%(int)pow(10,j)/(int)pow(10,j-1)){

        		return false;
        	}
        }

        return true;
    }
};

int main(){
	Solution* a;
	a = new Solution();
	cout<<a->isPalindrome(1)<<endl;
}