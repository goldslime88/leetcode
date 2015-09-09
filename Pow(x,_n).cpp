#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

    	if( n == 1 ){
    		return x;
    	}
    	else if( n == 0 ){
    		return 1;
    	}
    	else if( n < 0 ){
    		if( n == -2147483648){
    			return myPow(1/(x*x), 107374182);
    		}
    		return myPow(1/x, int(-n));
    	}
    	else{
    		if(n%2 == 0){
    			return myPow(x*x, n/2);
    		}
    		else{
    			return x*myPow(x*x, n/2);
    		}
    	}

    }
};