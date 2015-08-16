#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
    	int num = 0;
    	while(n){
    		if(n&1){
    			num++;
    		}
    		n = n>>1;

    	}

    	return num;
        
    }
};

int main(){
	Solution* a;
	a = new Solution();
	cout<< a->hammingWeight(11)<<endl;
}