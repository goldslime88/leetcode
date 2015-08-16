#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	vector<int> v;
    	v.push_back(1);
    	v.push_back(1);
    	if(n == 1){
    		return 1;
    	}
        for(int i = 2; i <= n; ++i){
            int a = v[i-1] + v[i-2];
        	v.push_back(a);
        }

        return v[n];
    }
};

int main(){
	Solution* a;
	a = new Solution();
	cout<< a->climbStairs(4)<<endl;

}