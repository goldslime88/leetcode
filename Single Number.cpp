#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
    	unordered_map<int,int> count;

    	    for(int i = 0; i < n; ++i){
    	    	unordered_map<int,int>::iterator it = count.find(A[i]);
    	    	if(it != count.end()){
    	    		count.erase(it);
    	    	}
    	    	else{
    	    		count[A[i]] = 0;
    	    		
       	    	}
        	
    	
    	}

    	return (count.begin())->first;


        
    }
};

