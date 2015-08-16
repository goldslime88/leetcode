#include <iostream>
#include <vector>
using std::vector;


class Solution {
public:
	Solution(){}
    void merge(int A[], int m, int B[], int n) {
    	vector<int> a, b, sort;
    	for(int i = 0; i < m; ++i){
    		a.push_back(A[i]);
    	}
    	for(int i = 0; i < n; ++i){
    		b.push_back(B[i]);
    	}

    	vector<int>::iterator ita, itb;
    	ita = a.begin();
    	itb = b.begin();
    	while(ita != a.end() && itb != b.end()){
    		if((*ita) <= (*itb)){
    			sort.push_back(*ita);
    			++ita;
    		}
    		if((*ita) > (*itb)){
    			sort.push_back(*itb);
    			++itb;
    		}

    	}
    	while(ita!=a.end()){
    		sort.push_back(*ita);
    		++ita;
    	}
    	while(itb!=b.end()){
    		sort.push_back(*itb);
    		++itb;
    	}
    	int i = 0;

    	for(vector<int>::iterator it = sort.begin(); it != sort.end(); ++it){
    		A[i] = *it;
    		++i;

    	}




        
    }
};

int main(){
	Solution *a;
	a = new Solution();

	

}