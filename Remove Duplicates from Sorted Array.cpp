#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n == 0){
    		return 0;
    	}
    	int temp = A[0];
    	int length = 1;
    	for(int i = 1; i < n; ++i){
    		if(A[i] == temp){
    			

    		}
    		else{
    			temp = A[i];
    			A[length] = temp;
    			length++;
    		}

    	}
    	return length;

        
    }
};

int main(){
	Solution* a;
	a = new Solution();
	int A[3] = {1, 1, 2};
	cout << a->removeDuplicates(A, 3)<<endl;
	for(int i = 0; i < 3; ++i){
		cout<<A[i]<<endl;

	}

	

}