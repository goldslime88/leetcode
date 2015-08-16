#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {

    	if(x == 0){
    		return 0;
    	}
   

    	long int num = (long)x, sum = 0;
    	while(num != 0){
    		
    		sum = sum*10 + num%10;
    		num = num/10;
    			

    	}

    	if(sum < INT_MIN || sum > INT_MAX){
    		return 0;
    	}

    	

    	return sum;
        
    }
};

int main(){
	Solution *a;
	a = new Solution();
	cout<< a->reverse(-2147483648)<<endl;


}