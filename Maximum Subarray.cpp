#include <iostream>
#include <limits>
using namespace std;



class Solution {

public:
    int maxSubArray(int A[], int n) {
        return maxArray(A, 0, n-1);
    }

    int maxArray(int A[], int begin, int end){
    	if(begin == end){
    		return A[begin];
    	}
    	else{
    		int mid = (begin+end)/2;
    		int maxleft = numeric_limits<int>::min() ,maxright = numeric_limits<int>::min();
    		int sumleft = 0, sumright = 0;
    		for(int i = mid; i >= begin; --i){
    			sumleft = sumleft + A[i];
    			if(sumleft > maxleft){
    				maxleft = sumleft;
    			}
    		}

    		for(int i = mid + 1; i <= end; ++i){
    			sumright = sumright + A[i];
    			if(sumright > maxright){
    				maxright = sumright;
    			}
    		}



    		return max( maxleft + maxright , maxArray(A, begin, mid), maxArray(A, mid+1, end));



    	}


    }

    int max(int a, int b, int c){
    	if(a>=b&&a>=c){
    		return a;
    	}
    	else if(b>=c&&b>=a){
    		return b;
    	}
    	else{
    		return c;
    	}
    }
};

int main(){
	Solution *a;
	a = new Solution();
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	cout<< a->maxSubArray(A, 9)<<endl;





}