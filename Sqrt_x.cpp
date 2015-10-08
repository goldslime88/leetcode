#include <iostream>
#include <cmath>
using namespace std;

class mySolution {
public:
    int mySqrt(int x) {
    	if(x < 0){
    		return 0;
    	}
        int head = 0;
        int tail = x;
        while(head<=tail){
        	int mid = (head+tail)/2;
        	if(mid*mid == x){
        		return mid;
        	}
        	if(mid*mid > x){
        		tail = mid - 1;
        	}
        	else{
        		head = mid + 1;
        	}
        }

        return tail;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        double ans = 1;
        double err = 0.0001;
        while(fabs(ans*ans - (double)x) > err){
        	ans = (ans + x/ans)/2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->mySqrt(16)<<endl;
	return 0;
}