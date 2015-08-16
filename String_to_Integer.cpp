#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
    	long long int sum = 0;
    	bool isPositive;
    	const char *temp = str;
    	while(*temp == ' '&& *temp != '\0'){
    		temp++;
    	}
    	if(*temp == '\0'){
    		return 0;
    	}

    	if(*temp >= '0'&& *temp <= '9'){
    		
    		while(*temp >= '0'&& *temp <= '9'&&temp != '\0'){
    			sum = 10*sum + (long long)(*temp-'0');
    			if(sum > INT_MAX){
    			return INT_MAX;
    		    }

    			temp++;
    		}
    		if(sum > INT_MAX){
    			return INT_MAX;
    		}
    		else{
    			return sum;
    		}

    	}
    	else if(*temp == '-'){

    		isPositive = false;
    		temp++;
       		while(*temp >= '0'&& *temp <= '9'&&temp != '\0'){
    			sum = 10*sum + (long long)(*temp-'0');
    			if(-1 * sum < INT_MIN){
    			return INT_MIN;
    		    }
    			temp++;
    		}
    		


    		if(-1 *sum < INT_MIN){
    			return INT_MIN;
    		}
    		else{
    			return -1*sum;
    		}


    	}
    	else if(*temp == '+'){
    		isPositive = true;
    		temp++;
    		while(*temp >= '0'&& *temp <= '9'&&temp != '\0'){
    			sum = 10*sum + (long long)(*temp-'0');
    			if(sum > INT_MAX){
    			return INT_MAX;
    		    }

    			temp++;
    		}
    		if(sum > INT_MAX){
    			return INT_MAX;
    		}
    		else{
    			return sum;
    		}




    	}
    	else{
    		return 0;
    	}


        
    }
};

int main(){
	Solution* a;
	a = new Solution();
	cout<< a-> atoi("-2147483649")<<endl;
	
}