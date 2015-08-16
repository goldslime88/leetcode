#include <iostream>

class Solution {
public:
	Solution(){}
    int trailingZeroes(int n) {
    	int ans=0;
    	if(n == 0){
    		return 0;
    	}
    	while(n/5 > 0){
    		ans = ans+n/5;
    		n = n/5;

    	}

    	return ans;

        
    }
};

int main(){
	Solution* a;
	a = new Solution();

	std::cout<< a->trailingZeroes(100)<<std::endl;

}