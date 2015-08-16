#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int,int> record;
        unordered_map<int, int>::iterator it;
        for(int i = 0; i < n; ++i){
        	it = record.find(A[i]);
        	if(it == record.end()){
        		record[A[i]] = 1;
        	}
        	else{
        		if(it->second == 1){
        			it->second = 2;	
        		}
        		else{
        			record.erase(A[i]);
        		}
        	}

        }

        it = record.begin();
        return it->first;

    }
};

int main(){
	Solution *a;
	a = new Solution();
	int A[] = {1, 1, 1, 2, 3, 3, 3};
	cout << a->singleNumber(A, 7)<<endl;
}